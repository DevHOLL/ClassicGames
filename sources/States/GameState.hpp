#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>

#include "Doom/Camera.hpp"
#include "Doom/Doom.hpp"
#include "States/AbstractState.hpp"
#include "States/LoadingState.hpp"
#include "Math/Vector.hpp"
  
namespace Game
{
  class GameState : public Game::AbstractState
  {
  private:
    sf::Time					_elapsed;	// Elapsed time since creation
    Game::Doom					_doom;		// Instance of current level
    Game::Camera				_camera;	// Camera to render level

    bool	updatePlayer(sf::Time);

    void	drawCamera();	// Render cameras
    void	drawImage();	// Draw rendered image to screen

  public:
    GameState();
    ~GameState() override;

    bool	initialize();			// Load resources and levels from WAD file
    bool	update(sf::Time) override;	// Update state
    void	draw() override;		// Draw state
  };
};

#endif
