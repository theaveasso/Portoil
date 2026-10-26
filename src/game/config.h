#pragma once

constexpr int ARENA_WIDTH = 1280;
constexpr int ARENA_HEIGHT = 720;

constexpr float PLAYER_SPEED = 300;
constexpr float PLAYER_RADIUS = 14;
constexpr float PLAYER_SKILL_COOLDOWN = 5;
constexpr int PLAYER_MAX_HEALTH = 3;
constexpr float PLAYER_INVULN_WINDOW = 1;

constexpr float DASH_DISTANCE = 110;
constexpr float DASH_DURATION = 0.09F;
constexpr float DASH_SPEED = DASH_DISTANCE / DASH_DURATION;
constexpr float DASH_COOLDOWN = 0.6F;

constexpr float PROJECTILE_SPEED = 600.F;
constexpr float PROJECTILE_RADIUS = 4.F;
constexpr float PROJECTILE_LIFESPAN = 1.5F;

constexpr float FIRE_COOLDOWN = 0.14F;

constexpr int MAX_ENTITIES = 64;
constexpr int MAX_PROJECTILES = 256;
