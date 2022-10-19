#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

#define BLOCKSIZE 64;

class Engine {
private:
	int windowWidth = 1368;
	int windowHeight = 768;	
	int FPS = 60;
	Clock clock;


public:
	int getWindowWidth()
	{
		return windowWidth;
	}

	int getWindowHeight()
	{
		return windowHeight;
	}

	void setWindowWidth(int windowWidht)
	{
		this->windowWidth=windowWidth;
	}

	void setWindowHeight(int windowHeight)
	{
		this->windowHeight=windowHeight;
	}

	int getFPS()
	{
		return FPS;
	}

	void setFPS(int FPS)
	{
		this->FPS = FPS;
	}
	
	
	int game()
	{
		RenderWindow window(VideoMode(windowWidth, windowHeight), "TEST");
		window.setFramerateLimit(FPS);

		Clock clock;	

		Texture woodTX;
		woodTX.loadFromFile("wood_floor.jpg");
		Sprite wood;
		wood.setTexture(woodTX);

		int woodX =512;
		int woodY =512;
		wood.setPosition(woodX, woodY);
		

		while (window.isOpen()) {

			Time timer = clock.getElapsedTime();
			float delay = timer.asSeconds();

			std::cout << delay << std::endl;

			if ((Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}

			if (delay > 0.3f)
			{
				if ((Keyboard::isKeyPressed(Keyboard::W)))
				{
					woodY = woodY - 64;
					wood.setPosition(woodX, woodY);
					clock.restart();
				}
				else if (Keyboard::isKeyPressed(Keyboard::S))
				{
					woodY = woodY + 64;
					wood.setPosition(woodX, woodY);
					clock.restart();
				}
				else if (Keyboard::isKeyPressed(Keyboard::A))
				{
					woodX = woodX - 64;
					wood.setPosition(woodX, woodY);
					clock.restart();
				}
				else if (Keyboard::isKeyPressed(Keyboard::D))
				{
					woodX = woodX + 64;
					wood.setPosition(woodX, woodY);
					clock.restart();
				}
			}
			
			


			window.draw(wood);
			window.display();
			window.clear(Color::Black);
		}
		return 0;
	}
};



int main()
{
	Engine game;
	game.game();

}
