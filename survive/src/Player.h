#pragma once

#include "Rectangle.h"

#include <memory>

struct InputData;

class Game;
class Weapon;

enum eDirection
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

class Player : public Rectangle
{
public:
    Player(Game* pGame);
    virtual ~Player() {}
    
    bool initialise();
    void move(InputData inputData, float deltaTime);
    void attack();
    void update(float deltaTime);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool isDead() const { return m_isDead; }
    void setIsDead(bool isDead) { m_isDead = isDead; }

    Weapon* getWeapon() { return m_pWeapon.get(); }

private:
    bool    m_isDead = false;
    eDirection m_direction = LEFT;
    Game*   m_pGame;
    std::unique_ptr<Weapon> m_pWeapon;
	eDirection old_direction = LEFT;
	float PlayerHeight = 55.0f;
	float PlayerWidth = 55.0f;
	float PlayerSpeed = 155.0f;
};
