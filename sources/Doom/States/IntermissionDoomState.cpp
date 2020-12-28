#include "System/Window.hpp"
#include "Doom/States/GameDoomState.hpp"
#include "Doom/States/IntermissionDoomState.hpp"
#include "Doom/States/TransitionDoomState.hpp"
#include "Doom/Thing/PlayerThing.hpp"

const int DOOM::IntermissionDoomState::TitleY = 2;
const int DOOM::IntermissionDoomState::StatsSoloX = 50;
const int DOOM::IntermissionDoomState::StatsSoloY = 50;
const int DOOM::IntermissionDoomState::StatsSoloSpacing = 33;
const int DOOM::IntermissionDoomState::StatsCoopX = 64;
const int DOOM::IntermissionDoomState::StatsCoopY = 50;
const int DOOM::IntermissionDoomState::StatsCoopSpacing = 64;
const int DOOM::IntermissionDoomState::TimeX = 16;
const int DOOM::IntermissionDoomState::TimeY = DOOM::Doom::RenderHeight - 32;
const int DOOM::IntermissionDoomState::SpeedPercent = 2;
const int DOOM::IntermissionDoomState::SpeedTime = 3;
const int DOOM::IntermissionDoomState::SpeedPistol = 4;

const std::array<std::array<sf::Vector2i, 9>, 3> DOOM::IntermissionDoomState::_positions =
{
  std::array<sf::Vector2i, 9>{  // KNEE-DEEP IN THE DEAD
      sf::Vector2i(185, 164),   // HANGAR
      sf::Vector2i(148, 143),   // NUCLEAR PLANT
      sf::Vector2i(69, 122),    // TOXIN REFINERY
      sf::Vector2i(209, 102),   // COMMAND CONTROL
      sf::Vector2i(116, 89),    // PHOBOS LAB
      sf::Vector2i(166, 55),    // CENTRAL PROCESSING
      sf::Vector2i(71, 56),     // COMPUTER STATION
      sf::Vector2i(135, 29),    // PHOBOS ANOMALY
      sf::Vector2i(71, 24)      // MILITARY BASE
  },
  std::array<sf::Vector2i, 9>{  // THE SHORES OF HELL
      sf::Vector2i(254, 25),    // DEIMOS ANOMALY
      sf::Vector2i(97, 50),     // CONTAINMENT AREA
      sf::Vector2i(188, 64),    // REFINERY
      sf::Vector2i(128, 78),    // DEIMOS LAB
      sf::Vector2i(214, 92),    // COMMAND CENTER
      sf::Vector2i(133, 130),   // HALLS OF THE DAMNED
      sf::Vector2i(208, 136),   // SPAWNING VATS
      sf::Vector2i(148, 140),   // TOWER OF BABEL
      sf::Vector2i(235, 158)    // FORTRESS OF MYSTERY
  },
  std::array<sf::Vector2i, 9>{  // INFERNO
      sf::Vector2i(156, 168),   // HELL KEEP
      sf::Vector2i(48, 154),    // SLOUGH OF DESPAIR
      sf::Vector2i(174, 95),    // PANDEMONIUM
      sf::Vector2i(265, 75),    // HOUSE OF PAIN
      sf::Vector2i(130, 48),    // UNHOLY CATHEDRAL
      sf::Vector2i(279, 23),    // MT. EREBUS
      sf::Vector2i(198, 48),    // GATE TO LIMBO
      sf::Vector2i(140, 25),    // DIS
      sf::Vector2i(281, 136)    // WARRENS
  }
};

const std::array<std::vector<DOOM::IntermissionDoomState::Animation>, 3>  DOOM::IntermissionDoomState::_animations =
{
  std::vector<DOOM::IntermissionDoomState::Animation>{
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00000"), DOOM::str_to_key("WIA00001"), DOOM::str_to_key("WIA00002") }, { 224, 104 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00100"), DOOM::str_to_key("WIA00101"), DOOM::str_to_key("WIA00102") }, { 184, 160 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00200"), DOOM::str_to_key("WIA00201"), DOOM::str_to_key("WIA00202") }, { 112, 136 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00300"), DOOM::str_to_key("WIA00301"), DOOM::str_to_key("WIA00302") }, { 72, 112 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00400"), DOOM::str_to_key("WIA00401"), DOOM::str_to_key("WIA00402") }, { 88, 96 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00500"), DOOM::str_to_key("WIA00501"), DOOM::str_to_key("WIA00502") }, { 64, 48 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00600"), DOOM::str_to_key("WIA00601"), DOOM::str_to_key("WIA00602") }, { 192, 40 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00700"), DOOM::str_to_key("WIA00701"), DOOM::str_to_key("WIA00702") }, { 136, 16 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00800"), DOOM::str_to_key("WIA00801"), DOOM::str_to_key("WIA00802") }, { 80, 16 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA00900"), DOOM::str_to_key("WIA00901"), DOOM::str_to_key("WIA00902") }, { 64, 24 }, 0 }
  },
  std::vector<DOOM::IntermissionDoomState::Animation>{
    { 11, 0, { DOOM::str_to_key("WIA10000") }, { 128, 136 }, 2 },
    { 11, 0, { DOOM::str_to_key("WIA10100") }, { 128, 136 }, 3 },
    { 11, 0, { DOOM::str_to_key("WIA10200") }, { 128, 136 }, 4 },
    { 11, 0, { DOOM::str_to_key("WIA10300") }, { 128, 136 }, 5 },
    { 11, 0, { DOOM::str_to_key("WIA10400") }, { 128, 136 }, 6 },
    { 11, 0, { DOOM::str_to_key("WIA10500") }, { 128, 136 }, 7 },
    { 11, 0, { DOOM::str_to_key("WIA10600") }, { 128, 136 }, 8 },
    { 11, 0, { DOOM::str_to_key("WIA10700"), DOOM::str_to_key("WIA10701"), DOOM::str_to_key("WIA10702") }, { 192, 144 }, 9 },
    { 11, 0, { DOOM::str_to_key("WIA10400") }, { 128, 136 }, 9 }
  },
  std::vector<DOOM::IntermissionDoomState::Animation>{
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA20000"), DOOM::str_to_key("WIA20001"), DOOM::str_to_key("WIA20002") }, { 104, 168 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA20100"), DOOM::str_to_key("WIA20101"), DOOM::str_to_key("WIA20102") }, { 40, 136 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA20200"), DOOM::str_to_key("WIA20201"), DOOM::str_to_key("WIA20202") }, { 160, 96 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA20300"), DOOM::str_to_key("WIA20301"), DOOM::str_to_key("WIA20302") }, { 104, 80 }, 0 },
    { 11, std::rand() % 11, { DOOM::str_to_key("WIA20400"), DOOM::str_to_key("WIA20401"), DOOM::str_to_key("WIA20402") }, { 120, 32 }, 0 },
    { 8, std::rand() % 8, { DOOM::str_to_key("WIA20500"), DOOM::str_to_key("WIA20501"), DOOM::str_to_key("WIA20502") }, { 40, 0 }, 0 }
  }
};

DOOM::IntermissionDoomState::IntermissionDoomState(Game::StateMachine& machine, DOOM::Doom& doom, bool secret) :
  Game::AbstractState(machine),
  _doom(doom),
  _next(getNextLevel(secret)),
  _state(DOOM::IntermissionDoomState::State::StateStats),
  _elapsed(sf::Time::Zero),
  _nextElapsed(sf::Time::Zero),
  _kills(),
  _items(),
  _secrets(),
  _times(),
  _background(getTexture(DOOM::str_to_key(
    (doom.mode == DOOM::Enum::Mode::ModeCommercial || (doom.mode == DOOM::Enum::Mode::ModeRetail && doom.level.episode.first == 4))
    ? (std::string("INTERPIC"))
    : (std::string("WIMAP") + std::to_string(doom.level.episode.first - 1))
  ))),
  _playerFace(getTexture(DOOM::str_to_key("STFST01"))),
  _playerBackground
    {
      getTexture(DOOM::str_to_key("STPB0")),
      getTexture(DOOM::str_to_key("STPB1")),
      getTexture(DOOM::str_to_key("STPB2")),
      getTexture(DOOM::str_to_key("STPB3"))
    },
  _textCurrent(getTexture(DOOM::str_to_key(
    (doom.mode == DOOM::Enum::Mode::ModeCommercial)
    ? (std::string("CWILV") + std::to_string((doom.level.episode.second - 1) / 10 % 10) + std::to_string((doom.level.episode.second - 1) % 10))
    : (std::string("WILV") + std::to_string(doom.level.episode.first - 1) + std::to_string(doom.level.episode.second - 1))
  ))),
  _textNext(getTexture(DOOM::str_to_key(
    (doom.mode == DOOM::Enum::Mode::ModeCommercial)
    ? (std::string("CWILV") + std::to_string((_next.second - 1) / 10 % 10) + std::to_string((_next.second - 1) % 10))
    : (std::string("WILV") + std::to_string(_next.first - 1) + std::to_string(_next.second - 1))
  ))),
  _textNumbers
    {
      getTexture(DOOM::str_to_key("WINUM0")),
      getTexture(DOOM::str_to_key("WINUM1")),
      getTexture(DOOM::str_to_key("WINUM2")),
      getTexture(DOOM::str_to_key("WINUM3")),
      getTexture(DOOM::str_to_key("WINUM4")),
      getTexture(DOOM::str_to_key("WINUM5")),
      getTexture(DOOM::str_to_key("WINUM6")),
      getTexture(DOOM::str_to_key("WINUM7")),
      getTexture(DOOM::str_to_key("WINUM8")),
      getTexture(DOOM::str_to_key("WINUM9"))
    },
  _textFinished(getTexture(DOOM::str_to_key("WIF"))),
  _textEntering(getTexture(DOOM::str_to_key("WIENTER"))),
  _textKills(getTexture(DOOM::str_to_key("WIOSTK"))),
  _textItems(getTexture(DOOM::str_to_key("WIOSTI"))),
  _textSecret(getTexture(DOOM::str_to_key("WISCRT2"))),
  _textScrt(getTexture(DOOM::str_to_key("WIOSTS"))),
  _textTime(getTexture(DOOM::str_to_key("WITIME"))),
  _textSucks(getTexture(DOOM::str_to_key("WISUCKS"))),
  _textPar(getTexture(DOOM::str_to_key("WIPAR"))),
  _textMinus(getTexture(DOOM::str_to_key("WIMINUS"))),
  _textPercent(getTexture(DOOM::str_to_key("WIPCNT"))),
  _textColon(getTexture(DOOM::str_to_key("WICOLON")))
{
  // Initialize counter for each player
  for (const auto& player : _doom.level.players) {
    _kills[player.get().id].value = -1.f / DOOM::Doom::Tic.asSeconds() * DOOM::IntermissionDoomState::SpeedPercent;
    _items[player.get().id].value = -1.f / DOOM::Doom::Tic.asSeconds() * DOOM::IntermissionDoomState::SpeedPercent;
    _secrets[player.get().id].value = -1.f / DOOM::Doom::Tic.asSeconds() * DOOM::IntermissionDoomState::SpeedPercent;
    _kills[player.get().id].max = (_doom.level.statistics.total.kills == 0) ? 0.f : std::round(_doom.level.statistics.players[player.get().id].kills * 100.f / _doom.level.statistics.total.kills);
    _items[player.get().id].max = (_doom.level.statistics.total.items == 0) ? 0.f : std::round(_doom.level.statistics.players[player.get().id].items * 100.f / _doom.level.statistics.total.items);
    _secrets[player.get().id].max = (_doom.level.statistics.total.secrets == 0) ? 0.f : std::round(_doom.level.statistics.players[player.get().id].secrets * 100.f / _doom.level.statistics.total.secrets);
  }

  // Time counter
  _times[0].value = -1.f / DOOM::Doom::Tic.asSeconds() * DOOM::IntermissionDoomState::SpeedTime;
  _times[0].max = std::round(_doom.level.statistics.time.asSeconds());

  // Par counter
  _times[1].value = -1.f / DOOM::Doom::Tic.asSeconds() * DOOM::IntermissionDoomState::SpeedTime;
  _times[1].max = getPar(_doom.level.episode);
  if (std::isnan(_times[1].max) == true)
    _times[1].max = _times[1].value;
}

bool    DOOM::IntermissionDoomState::update(sf::Time elapsed)
{
  // Add time to counter
  _elapsed += elapsed;

  switch (_state) {
    // Update statistics
  case DOOM::IntermissionDoomState::State::StateStats:
    if (updateStatistics(elapsed) == true) {
      _state = DOOM::IntermissionDoomState::State::StateNext;
      _doom.sound(DOOM::Doom::Resources::Sound::EnumSound::Sound_sgcock);
      return false;
    }
    break;

    // Update next level
  case DOOM::IntermissionDoomState::State::StateNext:
    if (updateNext(elapsed) == true) {
      return false;
    }
    break;
  default:
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
  }

  return false;
}

void    DOOM::IntermissionDoomState::updateStatisticsCountersComplete(std::map<int, DOOM::IntermissionDoomState::Counter>& counters)
{
  // Complete every counter
  for (auto& counter : counters)
    counter.second.value = counter.second.max;
}

bool    DOOM::IntermissionDoomState::updateStatisticsCountersCheck(const std::map<int, DOOM::IntermissionDoomState::Counter>& counters)
{
  // Check for counters completion
  for (const auto& counter : counters)
    if (counter.second.value < counter.second.max)
      return false;

  // Success!
  return true;
}

void    DOOM::IntermissionDoomState::updateStatisticsCounters(sf::Time& elapsed, std::map<int, DOOM::IntermissionDoomState::Counter>& counters, int speed)
{
  // Does nothing if no time or already completed
  if (elapsed == sf::Time::Zero || updateStatisticsCountersCheck(counters) == true)
    return;

  sf::Time  copy = elapsed;
  int       start = std::numeric_limits<int>::max();
  int       end = std::numeric_limits<int>::min();

  for (auto& counter : counters) {
    // Already completed
    if (counter.second.value == counter.second.max)
      continue;

    // Counter for sound effet
    start = std::min(start, (int)std::round(counter.second.value / speed / DOOM::IntermissionDoomState::SpeedPistol));

    // Increase counter
    counter.second.value += copy.asSeconds() / DOOM::Doom::Tic.asSeconds() * speed;

    // Finished
    if (counter.second.value >= counter.second.max) {
      elapsed = std::min(elapsed, sf::seconds((counter.second.value - counter.second.max) / speed * DOOM::Doom::Tic.asSeconds()));
      counter.second.value = counter.second.max;
    }

    // Not completed, consume time
    else
      elapsed = sf::Time::Zero;

    // Counter for sound effet
    if (counter.second.value >= 0.f)
      end = std::max(end, (int)std::round(counter.second.value / speed / DOOM::IntermissionDoomState::SpeedPistol));
  }

  // TODO: will not explode if elapsed is exactly at zero
  // Counter completed, explode!
  if (updateStatisticsCountersCheck(counters) == true)
    _doom.sound(DOOM::Doom::Resources::Sound::EnumSound::Sound_barexp);

  // Shoot pistol
  else if (start < end && end >= 0)
    _doom.sound(DOOM::Doom::Resources::Sound::EnumSound::Sound_pistol);
}

bool    DOOM::IntermissionDoomState::updateStatistics(sf::Time elapsed)
{
  // Skip statistics
  if (updateSkip() == true) {
    // Skip kills count
    if (updateStatisticsCountersCheck(_kills) == false)
      updateStatisticsCountersComplete(_kills);
    // Skip items count
    else if (updateStatisticsCountersCheck(_items) == false)
      updateStatisticsCountersComplete(_items);
    // Skip secrets count
    else if (updateStatisticsCountersCheck(_secrets) == false)
      updateStatisticsCountersComplete(_secrets);
    // Skip time count
    else if (updateStatisticsCountersCheck(_times) == false)
      updateStatisticsCountersComplete(_times);
    else
      return true;

    // A stat has been skipped
    _doom.sound(DOOM::Doom::Resources::Sound::EnumSound::Sound_barexp);
    elapsed = sf::Time::Zero;
    return false;
  }

  // Percentages
  updateStatisticsCounters(elapsed, _kills, DOOM::IntermissionDoomState::SpeedPercent);
  updateStatisticsCounters(elapsed, _items, DOOM::IntermissionDoomState::SpeedPercent);
  updateStatisticsCounters(elapsed, _secrets, DOOM::IntermissionDoomState::SpeedPercent);

  // Times
  updateStatisticsCounters(elapsed, _times, DOOM::IntermissionDoomState::SpeedTime);

  return false;
}

bool    DOOM::IntermissionDoomState::updateNext(sf::Time elapsed)
{
  // Update Next state timer
  _nextElapsed += elapsed;

  // Ignore if not skipped
  if (updateSkip() == false)
    return false;

  // Copy current screen
  sf::Image start = _doom.image;

  // Load next level
  _doom.setLevel(_next);

  // Save references as 'this' is gonna be deleted
  Game::StateMachine& machine = _machine;
  DOOM::Doom& doom = _doom;

  // Swap to intermission with intermission
  machine.swap<DOOM::GameDoomState>(doom);

  // Simulate first frame of next level
  machine.draw();

  // Push transition
  machine.push<DOOM::TransitionDoomState>(doom, start, doom.image);

  return true;
}

bool    DOOM::IntermissionDoomState::updateSkip()
{
  bool  skip = false;

  // Check skip key
  for (const auto& player : _doom.level.players) {
    // Keyboard/mouse
    if (player.get().controller == 0) {
      skip |= Game::Window::Instance().keyboard().keyPressed(sf::Keyboard::Space);
      skip |= Game::Window::Instance().mouse().buttonPressed(sf::Mouse::Left);
    }

    else {
      skip |= Game::Window::Instance().joystick().buttonPressed(player.get().controller - 1, 0);
      skip |= Game::Window::Instance().joystick().buttonPressed(player.get().controller - 1, 1);
    }
  }

  return skip;
}

void	DOOM::IntermissionDoomState::draw()
{
  // Resize rendering target
  if (_doom.image.getSize() != sf::Vector2u(DOOM::Doom::RenderWidth, DOOM::Doom::RenderHeight))
    _doom.image.create(DOOM::Doom::RenderWidth, DOOM::Doom::RenderHeight);

  // Clear rendering target
  std::memset((void*)_doom.image.getPixelsPtr(), 0, _doom.image.getSize().x * _doom.image.getSize().y * sizeof(sf::Color));

  // Draw background
  drawBackground();

  // Draw screen infos
  switch (_state)
  {
  case DOOM::IntermissionDoomState::StateStats:
    drawStatistics();
    break;
  case DOOM::IntermissionDoomState::StateNext:
    drawNext();
    break;
  default:
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
  }
}

void	DOOM::IntermissionDoomState::drawBackground()
{
  // Draw background screen
  _background.draw(_doom, _doom.image, { 0, 0 }, { 1, 1 });

  // Draw animations only for DOOM I
  if (_doom.mode == DOOM::Enum::Mode::ModeShareware ||
    _doom.mode == DOOM::Enum::Mode::ModeRegistered ||
    _doom.mode == DOOM::Enum::Mode::ModeRetail) {

    // Cancel if no animation for current level
    if (_doom.level.episode.first < 1 || _doom.level.episode.first > _animations.size())
      return;

    // Draw every animations
    for (const auto& animation : _animations[_doom.level.episode.first - 1]) {
      if (animation.level == 0)
        getTexture(animation.frames[(_elapsed.asMicroseconds() / (animation.duration * DOOM::Doom::Tic.asMicroseconds()) + animation.offset) % animation.frames.size()]).draw(_doom, _doom.image, animation.position, sf::Vector2i(1, 1));
      else if (_next.second == animation.level)
        getTexture(animation.frames[std::min((_nextElapsed.asMicroseconds() / (animation.duration * DOOM::Doom::Tic.asMicroseconds()) + animation.offset), (long long)animation.frames.size() - 1)]).draw(_doom, _doom.image, animation.position, sf::Vector2i(1, 1));
    }
  }
}

void	DOOM::IntermissionDoomState::drawStatistics()
{
  // Draw title
  _textCurrent.draw(_doom, _doom.image, sf::Vector2i((DOOM::Doom::RenderWidth - _textCurrent.width) / 2, DOOM::IntermissionDoomState::TitleY), { 1, 1 });
  _textFinished.draw(_doom, _doom.image, sf::Vector2i((DOOM::Doom::RenderWidth - _textFinished.width) / 2, DOOM::IntermissionDoomState::TitleY + _textCurrent.height * 5 / 4), { 1, 1 });

  // Draw statistics
  if (_doom.level.players.size() == 1)
    drawStatisticsSolo();
  else if (_doom.level.players.size() > 1)
    drawStatisticsCoop();
  else
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
}

void	DOOM::IntermissionDoomState::drawStatisticsSolo()
{
  // Draw solo stats titles
  _textKills.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 0 * _textNumbers[0].get().height * 3 / 2), { 1, 1 });
  _textItems.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 1 * _textNumbers[0].get().height * 3 / 2), { 1, 1 });
  _textSecret.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 2 * _textNumbers[0].get().height * 3 / 2), { 1, 1 });
  _textTime.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), { 1, 1 });
  if (std::isnan(getPar(_doom.level.episode)) == false)
    _textPar.draw(_doom, _doom.image, sf::Vector2i(DOOM::Doom::RenderWidth / 2 + DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), { 1, 1 });

  // Draw statistics
  if (_kills.begin()->second.value >= 0.f)
    drawPercent(sf::Vector2i(DOOM::Doom::RenderWidth - DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 0 * _textNumbers[0].get().height * 3 / 2), (int)_kills.begin()->second.value);
  if (_items.begin()->second.value >= 0.f)
    drawPercent(sf::Vector2i(DOOM::Doom::RenderWidth - DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 1 * _textNumbers[0].get().height * 3 / 2), (int)_items.begin()->second.value);
  if (_secrets.begin()->second.value >= 0.f)
    drawPercent(sf::Vector2i(DOOM::Doom::RenderWidth - DOOM::IntermissionDoomState::StatsSoloX, DOOM::IntermissionDoomState::StatsSoloY + 2 * _textNumbers[0].get().height * 3 / 2), (int)_secrets.begin()->second.value);
  if (_times[0].value >= 0.f)
    drawTime(sf::Vector2i(DOOM::Doom::RenderWidth / 2 - DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), (int)_times[0].value);
  if (_times[1].value >= 0.f)
    drawTime(sf::Vector2i(DOOM::Doom::RenderWidth - DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), (int)_times[1].value);
}

void	DOOM::IntermissionDoomState::drawStatisticsCoop()
{
  // Stats titles
  _textKills.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 + 1 * DOOM::IntermissionDoomState::StatsCoopSpacing - _textKills.width, DOOM::IntermissionDoomState::StatsCoopY), sf::Vector2i(1, 1));
  _textItems.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 + 2 * DOOM::IntermissionDoomState::StatsCoopSpacing - _textItems.width, DOOM::IntermissionDoomState::StatsCoopY), sf::Vector2i(1, 1));
  _textScrt.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 + 3 * DOOM::IntermissionDoomState::StatsCoopSpacing - _textScrt.width, DOOM::IntermissionDoomState::StatsCoopY), sf::Vector2i(1, 1));
  
  int y = DOOM::IntermissionDoomState::StatsCoopY + _textKills.height;

  // Draw stats of each player
  for (const auto& player : _doom.level.players) {
    _playerBackground[(player.get().id - 1) % _playerBackground.size()].get().draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 + 0 * DOOM::IntermissionDoomState::StatsCoopSpacing - _playerBackground[(player.get().id - 1) % _playerBackground.size()].get().width, y), sf::Vector2i(1, 1));
    _playerFace.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 + 0 * DOOM::IntermissionDoomState::StatsCoopSpacing - _playerBackground[(player.get().id - 1) % _playerBackground.size()].get().width, y), sf::Vector2i(1, 1));

    if (_kills.at(player.get().id).value >= 0.f)
      drawPercent(sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 - _textPercent.width + 1 * DOOM::IntermissionDoomState::StatsCoopSpacing, y + 10), (int)_kills.at(player.get().id).value);
    if (_items.at(player.get().id).value >= 0.f)
      drawPercent(sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 - _textPercent.width + 2 * DOOM::IntermissionDoomState::StatsCoopSpacing, y + 10), (int)_items.at(player.get().id).value);
    if (_secrets.at(player.get().id).value >= 0.f)
      drawPercent(sf::Vector2i(DOOM::IntermissionDoomState::StatsCoopX + _playerFace.width / 2 - _textPercent.width + 3 * DOOM::IntermissionDoomState::StatsCoopSpacing, y + 10), (int)_secrets.at(player.get().id).value);

    y += DOOM::IntermissionDoomState::StatsSoloSpacing;
  }

  // Draw time only if available space
  if (_doom.level.players.size() <= 3) {
    // Titles
    _textTime.draw(_doom, _doom.image, sf::Vector2i(DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), { 1, 1 });
    if (std::isnan(getPar(_doom.level.episode)) == false)
      _textPar.draw(_doom, _doom.image, sf::Vector2i(DOOM::Doom::RenderWidth / 2 + DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), { 1, 1 });

    // Stats
    if (_times[0].value >= 0.f)
      drawTime(sf::Vector2i(DOOM::Doom::RenderWidth / 2 - DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), (int)_times[0].value);
    if (_times[1].value >= 0.f)
      drawTime(sf::Vector2i(DOOM::Doom::RenderWidth - DOOM::IntermissionDoomState::TimeX, DOOM::IntermissionDoomState::TimeY), (int)_times[1].value);
  }
}

void	DOOM::IntermissionDoomState::drawNext()
{
  // Draw title
  _textEntering.draw(_doom, _doom.image, sf::Vector2i((DOOM::Doom::RenderWidth - _textEntering.width) / 2, DOOM::IntermissionDoomState::TitleY), { 1, 1 });
  _textNext.draw(_doom, _doom.image, sf::Vector2i((DOOM::Doom::RenderWidth - _textNext.width) / 2, DOOM::IntermissionDoomState::TitleY + _textEntering.height * 5 / 4), { 1, 1 });

  // Draw maps details only in DOOM (except eps. 4)
  if ((_doom.mode == DOOM::Enum::Mode::ModeShareware ||
    _doom.mode == DOOM::Enum::Mode::ModeRegistered ||
    _doom.mode == DOOM::Enum::Mode::ModeRetail) &&
    _next.first >= 1 && _next.first <= _positions.size()) {
    const DOOM::Doom::Resources::Texture& splat = getTexture(DOOM::str_to_key("WISPLAT"));

    // Draw blood splats
    for (int index = 0; index < _positions[_next.first - 1].size(); index++) {
      if ((_next.second == 9 && _doom.level.episode.second > index) ||
        (_doom.level.episode.second == 9 && (_next.second - 1 > index || 9 - 1 == index)) ||
        (_next.second != 9 && _doom.level.episode.second != 9 && _doom.level.episode.second > index)) {
        splat.draw(_doom, _doom.image, _positions[_next.first - 1][index], { 1, 1 });
      }
    }

    // Draw '<- You are here'
    if ((int)(_nextElapsed.asSeconds() / DOOM::Doom::Tic.asSeconds()) % 32 < 20 &&
      _next.second >= 1 && _next.second <= _positions[_next.first - 1].size()) {
      const DOOM::Doom::Resources::Texture& here0 = getTexture(DOOM::str_to_key("WIURH0"));
      const DOOM::Doom::Resources::Texture& here1 = getTexture(DOOM::str_to_key("WIURH1"));

      // Choose left of right arrow
      if (_positions[_next.first - 1][_next.second - 1].x - here0.left >= 0 &&
        _positions[_next.first - 1][_next.second - 1].x - here0.left + here0.width < (int)_doom.image.getSize().x &&
        _positions[_next.first - 1][_next.second - 1].y - here0.top >= 0 &&
        _positions[_next.first - 1][_next.second - 1].y - here0.top + here0.height < (int)_doom.image.getSize().y)
        here0.draw(_doom, _doom.image, _positions[_next.first - 1][_next.second - 1], { 1, 1 });
      else
        here1.draw(_doom, _doom.image, _positions[_next.first - 1][_next.second - 1], { 1, 1 });
    }
  }
}

void    DOOM::IntermissionDoomState::drawPercent(sf::Vector2i position, int value)
{
  // Draw percent symbol
  _textPercent.draw(_doom, _doom.image, position, { 1, 1 });

  // Draw percentage value
  do {
    position.x -= _textNumbers[value % 10].get().width;
    _textNumbers[value % 10].get().draw(_doom, _doom.image, position, { 1, 1 });

    value /= 10;
  } while (value != 0);
}

void    DOOM::IntermissionDoomState::drawTime(sf::Vector2i position, int value)
{
  // Sucks if over an hour
  if (value >= 60 * 60) {
    _textSucks.draw(_doom, _doom.image, { position.x - _textSucks.width, position.y }, { 1, 1 });
  }

  // Draw time
  else {
    // Seconds unit
    position.x -= _textNumbers[value % 10].get().width;
    _textNumbers[value % 10].get().draw(_doom, _doom.image, position, { 1, 1 });
    value /= 10;

    // Seconds decimal
    position.x -= _textNumbers[value % 6].get().width;
    _textNumbers[value % 6].get().draw(_doom, _doom.image, position, { 1, 1 });
    value /= 6;

    // Colon
    position.x -= _textColon.width;
    _textColon.draw(_doom, _doom.image, position, { 1, 1 });

    // Draw minutes only if superior to zero
    if (value > 0) {
      // Minutes unit
      position.x -= _textNumbers[value % 10].get().width;
      _textNumbers[value % 10].get().draw(_doom, _doom.image, position, { 1, 1 });
      value /= 10;

      // Minutes decimal
      position.x -= _textNumbers[value % 6].get().width;
      _textNumbers[value % 6].get().draw(_doom, _doom.image, position, { 1, 1 });
      value /= 6;
    }
  }
}

const DOOM::Doom::Resources::Texture& DOOM::IntermissionDoomState::getTexture(uint64_t key) const
{
  const auto  texture = _doom.resources.menus.find(key);

  // Throw error if texture doesn't exist
  if (texture == _doom.resources.menus.end())
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
  else
    return texture->second;
}

std::pair<uint8_t, uint8_t> DOOM::IntermissionDoomState::getNextLevel(bool secret) const
{
  switch (_doom.mode) {
  case DOOM::Enum::Mode::ModeShareware:   // DOOM 1 shareware, E1, M9
  {
    const std::map<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  shareware = {
      // KNEE-DEEP IN THE DEAD
      { { 1, 1 }, { 1, 2 } }, // HANGAR
      { { 1, 2 }, { 1, 3 } }, // NUCLEAR PLANT
      { { 1, 3 }, { 1, 4 } }, // TOXIN REFINERY
      { { 1, 4 }, { 1, 5 } }, // COMMAND CONTROL
      { { 1, 5 }, { 1, 6 } }, // PHOBOS LAB
      { { 1, 6 }, { 1, 7 } }, // CENTRAL PROCESSING
      { { 1, 7 }, { 1, 8 } }, // COMPUTER STATION
      // { { 1, 8 }, {} },    // PHOBOS ANOMALY
      { { 1, 9 }, { 1, 4 } }  // MILITARY BASE
    };

    // Secret level goes to level 9
    if (secret == true)
      return { _doom.level.episode.first, 9 };
    else if (shareware.find(_doom.level.episode) != shareware.end())
      return shareware.find(_doom.level.episode)->second;
  } break;

  case DOOM::Enum::Mode::ModeCommercial:  // DOOM 2 retail, E1 M34
  {
    const std::map<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  commercial = {
      { { 1, 1 }, { 1, 2 } },   // ENTRYWAY
      { { 1, 2 }, { 1, 3 } },   // UNDERHALLS
      { { 1, 3 }, { 1, 4 } },   // THE GANTLET
      { { 1, 4 }, { 1, 5 } },   // THE FOCUS
      { { 1, 5 }, { 1, 6 } },   // THE WASTE TUNNELS
      { { 1, 6 }, { 1, 7 } },   // THE CRUSHER
      { { 1, 7 }, { 1, 8 } },   // DEAD SIMPLE
      { { 1, 8 }, { 1, 9 } },   // TRICKS AND TRAPS
      { { 1, 9 }, { 1, 10 } },  // THE PIT
      { { 1, 10 }, { 1, 11 } }, // REFUELING BASE
      { { 1, 11 }, { 1, 12 } }, // CIRCLE OF DEATH
      { { 1, 12 }, { 1, 13 } }, // THE FACTORY
      { { 1, 13 }, { 1, 14 } }, // DOWNTOWN
      { { 1, 14 }, { 1, 15 } }, // THE INMOST DENS
      { { 1, 15 }, { 1, 16 } }, // INDUSTRIAL ZONE
      { { 1, 16 }, { 1, 17 } }, // SUBURBS
      { { 1, 17 }, { 1, 18 } }, // TENEMENTS
      { { 1, 18 }, { 1, 19 } }, // THE COURTYARD
      { { 1, 19 }, { 1, 20 } }, // THE CITADEL
      { { 1, 20 }, { 1, 21 } }, // GOTCHA!
      { { 1, 21 }, { 1, 22 } }, // NIRVANA
      { { 1, 22 }, { 1, 23 } }, // THE CATACOMBS
      { { 1, 23 }, { 1, 24 } }, // BARRELS O' FUN
      { { 1, 24 }, { 1, 25 } }, // THE CHASM
      { { 1, 25 }, { 1, 26 } }, // BLOODFALLS
      { { 1, 26 }, { 1, 27 } }, // THE ABANDONED MINES
      { { 1, 27 }, { 1, 28 } }, // MONSTER CONDO
      { { 1, 28 }, { 1, 29 } }, // THE SPIRIT WORLD
      { { 1, 29 }, { 1, 30 } }, // THE LIVING END
      // { { 1, 30 }, {} },     // ICON OF SIN
      { { 1, 31 }, { 1, 16 } }, // WOLFENSTEIN
      { { 1, 32 }, { 1, 16 } }, // GROSSE
    };

    // Secret level goes to level 31 or 32
    if (secret == true)
      return (_doom.level.episode == std::pair<uint8_t, uint8_t>(1, 31)) ? std::pair<uint8_t, uint8_t>(1, 32) : std::pair<uint8_t, uint8_t>(1, 31);
    else if (commercial.find(_doom.level.episode) != commercial.end())
      return commercial.find(_doom.level.episode)->second;
  } break;

  case DOOM::Enum::Mode::ModeRegistered:  // DOOM 1 registered, E3, M27
  {
    const std::map<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  registered = {
      // KNEE-DEEP IN THE DEAD
      { { 1, 1 }, { 1, 2 } }, // HANGAR
      { { 1, 2 }, { 1, 3 } }, // NUCLEAR PLANT
      { { 1, 3 }, { 1, 4 } }, // TOXIN REFINERY
      { { 1, 4 }, { 1, 5 } }, // COMMAND CONTROL
      { { 1, 5 }, { 1, 6 } }, // PHOBOS LAB
      { { 1, 6 }, { 1, 7 } }, // CENTRAL PROCESSING
      { { 1, 7 }, { 1, 8 } }, // COMPUTER STATION
      // { { 1, 8 }, {} },    // PHOBOS ANOMALY
      { { 1, 9 }, { 1, 4 } }, // MILITARY BASE
      // THE SHORES OF HELL
      { { 2, 1 }, { 2, 2 } }, // DEIMOS ANOMALY
      { { 2, 2 }, { 2, 3 } }, // CONTAINMENT AREA
      { { 2, 3 }, { 2, 4 } }, // REFINERY
      { { 2, 4 }, { 2, 5 } }, // DEIMOS LAB
      { { 2, 5 }, { 2, 6 } }, // COMMAND CENTER
      { { 2, 6 }, { 2, 7 } }, // HALLS OF THE DAMNED
      { { 2, 7 }, { 2, 8 } }, // SPAWNING VATS
      // { { 2, 8 }, {} },    // TOWER OF BABEL
      { { 2, 9 }, { 2, 6 } }, // FORTRESS OF MYSTERY
      // INFERNO
      { { 3, 1 }, { 3, 2 } }, // HELL KEEP
      { { 3, 2 }, { 3, 3 } }, // SLOUGH OF DESPAIR
      { { 3, 3 }, { 3, 4 } }, // PANDEMONIUM
      { { 3, 4 }, { 3, 5 } }, // HOUSE OF PAIN
      { { 3, 5 }, { 3, 6 } }, // UNHOLY CATHEDRAL
      { { 3, 6 }, { 3, 7 } }, // MT. EREBUS
      { { 3, 7 }, { 3, 8 } }, // GATE TO LIMBO
      // { { 3, 8 }, {} },    // DIS
      { { 3, 9 }, { 3, 7 } }  // WARRENS
    };

    // Secret level goes to level 9
    if (secret == true)
      return { _doom.level.episode.first, 9 };
    else if (registered.find(_doom.level.episode) != registered.end())
      return registered.find(_doom.level.episode)->second;
  } break;

  case DOOM::Enum::Mode::ModeRetail:      // DOOM 1 retail, E4, M36
  {
    const std::map<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  retail = {
      // KNEE-DEEP IN THE DEAD
      { { 1, 1 }, { 1, 2 } }, // HANGAR
      { { 1, 2 }, { 1, 3 } }, // NUCLEAR PLANT
      { { 1, 3 }, { 1, 4 } }, // TOXIN REFINERY
      { { 1, 4 }, { 1, 5 } }, // COMMAND CONTROL
      { { 1, 5 }, { 1, 6 } }, // PHOBOS LAB
      { { 1, 6 }, { 1, 7 } }, // CENTRAL PROCESSING
      { { 1, 7 }, { 1, 8 } }, // COMPUTER STATION
      // { { 1, 8 }, {} },    // PHOBOS ANOMALY
      { { 1, 9 }, { 1, 4 } }, // MILITARY BASE
      // THE SHORES OF HELL
      { { 2, 1 }, { 2, 2 } }, // DEIMOS ANOMALY
      { { 2, 2 }, { 2, 3 } }, // CONTAINMENT AREA
      { { 2, 3 }, { 2, 4 } }, // REFINERY
      { { 2, 4 }, { 2, 5 } }, // DEIMOS LAB
      { { 2, 5 }, { 2, 6 } }, // COMMAND CENTER
      { { 2, 6 }, { 2, 7 } }, // HALLS OF THE DAMNED
      { { 2, 7 }, { 2, 8 } }, // SPAWNING VATS
      // { { 2, 8 }, {} },    // TOWER OF BABEL
      { { 2, 9 }, { 2, 6 } }, // FORTRESS OF MYSTERY
      // INFERNO
      { { 3, 1 }, { 3, 2 } }, // HELL KEEP
      { { 3, 2 }, { 3, 3 } }, // SLOUGH OF DESPAIR
      { { 3, 3 }, { 3, 4 } }, // PANDEMONIUM
      { { 3, 4 }, { 3, 5 } }, // HOUSE OF PAIN
      { { 3, 5 }, { 3, 6 } }, // UNHOLY CATHEDRAL
      { { 3, 6 }, { 3, 7 } }, // MT. EREBUS
      { { 3, 7 }, { 3, 8 } }, // GATE TO LIMBO
      // { { 3, 8 }, {} },    // DIS
      { { 3, 9 }, { 3, 7 } }, // WARRENS
      // THY FLESH CONSUMED
      { { 4, 1 }, { 4, 2 } }, // HELL BENEATH
      { { 4, 2 }, { 4, 3 } }, // PERFECT HATRED
      { { 4, 3 }, { 4, 4 } }, // SEVER THE WICKED
      { { 4, 4 }, { 4, 5 } }, // UNRULY EVIL
      { { 4, 5 }, { 4, 6 } }, // THEY WILL REPENT
      { { 4, 6 }, { 4, 7 } }, // AGAINST THEE WICKEDLY
      { { 4, 7 }, { 4, 8 } }, // AND HELL FOLLOWED
      // { { 4, 8 }, {} },    // UNTO THE CRUEL
      { { 4, 9 }, { 4, 3 } }  // FEAR
    };

    // Secret level goes to level 9
    if (secret == true)
      return { _doom.level.episode.first, 9 };
    else if (retail.find(_doom.level.episode) != retail.end())
      return retail.find(_doom.level.episode)->second;
  } break;

  default:
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
    break;
  }

  // Impossible, should not happen
  throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
}

float   DOOM::IntermissionDoomState::getPar(std::pair<uint8_t, uint8_t> level) const
{
  // DOOM Par Times
  std::array<std::array<float, 9>, 3> doom = {
      std::array<float, 9>{ 30.f, 75.f, 120.f, 90.f, 165.f, 180.f, 180.f, 30.f, 165.f },
      std::array<float, 9>{ 90.f, 90.f, 90.f, 120.f, 90.f, 360.f, 240.f, 30.f, 170.f },
      std::array<float, 9>{ 90.f, 45.f, 90.f, 150.f, 90.f, 90.f, 165.f, 30.f, 135.f }
  };

  // DOOM II Par Times
  std::array<float, 32> doom2 = {
      30.f, 90.f, 120.f, 120.f, 90.f, 150.f, 120.f, 120.f, 270.f, 90.f,
      210.f, 150.f, 150.f, 150.f, 210.f, 150.f, 420.f, 150.f, 210.f, 150.f,
      240.f, 150.f, 180.f, 150.f, 150.f, 300.f, 330.f, 420.f, 300.f, 180.f,
      120.f, 30.f
  };

  switch (_doom.mode) {
    // DOOM shareware, DOOM I, Ultimate DOOM
  case DOOM::Enum::Mode::ModeShareware:
  case DOOM::Enum::Mode::ModeRegistered:
  case DOOM::Enum::Mode::ModeRetail:
    if (level.first - 1 < doom.size() && level.second - 1 < doom[level.first - 1].size())
      return doom[level.first - 1][level.second - 1];
    else
      return std::nanf("");

    // DOOM II
  case DOOM::Enum::Mode::ModeCommercial:
    if (level.first == 1 && level.second - 1 < doom2.size())
      return doom2[level.second];
    else
      return std::nanf("");

    // Error
  default:
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
  }
}