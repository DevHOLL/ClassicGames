#include "System/Library/FontLibrary.hpp"
#include "States/Menu/MainMenuState.hpp"
#include "States/StartState.hpp"
#include "States/StateMachine.hpp"
#include "System/Config.hpp"
#include "System/Window.hpp"

Game::StartState::StartState(Game::StateMachine& machine) :
  Game::AbstractState(machine),
  _elapsed(0.f),
  _text("PRESS START", Game::FontLibrary::Instance().get(Game::Config::ExecutablePath + "assets/fonts/pixelated.ttf"), 128)
{}

bool	Game::StartState::update(sf::Time elapsed)
{
  _elapsed += elapsed.asSeconds();

  // Switch to main menu when the player press start
  if (Game::Window::Instance().mouse().buttonPressed(sf::Mouse::Button::Left) == true ||
    Game::Window::Instance().keyboard().keyPressed(sf::Keyboard::Return) == true || Game::Window::Instance().keyboard().keyPressed(sf::Keyboard::Space) == true ||
    Game::Window::Instance().joystick().buttonPressed(0, 0) == true || Game::Window::Instance().joystick().buttonPressed(0, 7) == true)
  {
    _elapsed = 0.f;
    _machine.push<Game::MainMenuState>();
    return false;
  }

  return false;
}

void	Game::StartState::draw()
{
  // Set text position to the center of the screen
  float	scale = std::min((Game::Window::Instance().window().getSize().x * 2.f / 3.f) / _text.getLocalBounds().width, (Game::Window::Instance().window().getSize().y / 3.f) / _text.getLocalBounds().height);

  _text.setScale(scale, scale);
  _text.setPosition(sf::Vector2f((Game::Window::Instance().window().getSize().x - _text.getGlobalBounds().width) / 2.f, (Game::Window::Instance().window().getSize().y - _text.getGlobalBounds().height) / 2.f));
  
  // Set text color for flickering
  float	intensity = std::sqrtf(1.f - (std::cos(_elapsed * 4.f) + 1.f) / 2.f);

  _text.setFillColor(sf::Color((sf::Uint8)(255 * intensity), (sf::Uint8)(255 * intensity), (sf::Uint8)(255 * intensity)));

  // Draw PRESS START text
  Game::Window::Instance().window().draw(_text);
}