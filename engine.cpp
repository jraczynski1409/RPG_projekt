#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;

class Engine {
public:
	static const int mapWidth = 5;
	static const int mapHeight = 5;
	static const int blockSize = 64;
	static const int windowWidth = 1368;
	static const int windowHeight = 720;
	
	int isRun = 1;

	Engine() {

	}

	Sprite makeSprite(String path);
	
};

Sprite Engine::makeSprite(String path)
{
	Texture x;
	x.loadFromFile(path);
	Sprite a;
	a.setTexture(x);
	return a;
}





class Player {
public:
	String name;
	int lvl;
	Sprite outfit;

	int positionX;
	int positionY;

	Player(String name, int lvl, Sprite outfit)
	{
		this->name = name;
		this->lvl = lvl;
		this->outfit = outfit;

		this->positionX = 64;
		this->positionY = 64;
	}
};








int main()
{


	Engine engine;
	RenderWindow window(VideoMode(engine.windowWidth, engine.windowHeight), "TEST");
	window.setFramerateLimit(1);


	Sprite wood = engine.makeSprite("wood_floor.jpg");

	Player player("K", 1, wood);
	
	Clock c1;
	c1.getElapsedTime();
	
	Time t1;
	t1.asMilliseconds();

	while ((window.isOpen())) {

		
			
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.positionY = player.positionY - 64;
				player.outfit.setPosition(player.positionX, player.positionY);
				
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.positionY = player.positionY + 64;
				player.outfit.setPosition(player.positionX, player.positionY);

			}
			else if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.positionX = player.positionX - 64;
				player.outfit.setPosition(player.positionX, player.positionY);

			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.positionX = player.positionX + 64;
				player.outfit.setPosition(player.positionX, player.positionY);

			}

		window.draw(player.outfit);
		window.display();

		window.clear(Color::Black);
	}

}

