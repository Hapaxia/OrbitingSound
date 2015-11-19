// Orbiting Sound

// 2015 by Hapax (https://github.com/Hapaxia)

// CC0 (CC zero license)



// comment out the next line for only Orbiting Sound audio or have it un-commented out to display the Orbiting Sound interactive visualisation
#define SHOW_INTERACTIVE_VISUALISATION



#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#ifdef SHOW_INTERACTIVE_VISUALISATION
#include <SFML/Graphics.hpp>
#endif // SHOW_INTERACTIVE_VISUALISATION
int main()
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile("sinewave.ogg")) // simple sine wave provided. you can use any loopable sound including music clips
	{
		std::cerr << "Could not load sound." << std::endl;
		return EXIT_FAILURE;
	}
	sf::Sound sound(soundBuffer);
	sound.setLoop(true);
	sound.setPosition({ 0.f, 0.f, 1.f });
	sound.play();

#ifndef SHOW_INTERACTIVE_VISUALISATION
	const float speed{ 2.f };
	float angle{ 0.f };
	sf::Clock clock;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		angle += clock.restart().asSeconds() * speed;
		sound.setPosition(std::sin(angle), 0.f, -std::cos(angle));
	}
#else // SHOW_INTERACTIVE_VISUALISATION
	sf::RenderWindow window(sf::VideoMode(220, 220), "Orbiting Sound", sf::Style::Default);
	window.setFramerateLimit(60);
	sf::CircleShape graphicListener(20.f), graphicSound(10.f);
	graphicListener.setOrigin(graphicListener.getRadius(), graphicListener.getRadius());
	graphicSound.setOrigin(graphicSound.getRadius(), graphicSound.getRadius());
	graphicListener.setPosition(sf::Vector2f(window.getSize() / 2u));
	const float graphicOrbitDistance{ 100.f };
	const float acceleration{ 0.2f };
	float speed{ 2.f };
	bool isClockwise{ true };
	float angle{ 0.f };
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					isClockwise = !isClockwise;
				else if (event.key.code == sf::Keyboard::Add)
					speed += acceleration;
				else if (event.key.code == sf::Keyboard::Subtract)
				{
					speed -= acceleration;
					if (speed < 0.f)
						speed = 0.f;
				}
			}
		}
		angle += clock.restart().asSeconds() * (isClockwise ? speed : -speed);
		const float sine{ std::sin(angle) };
		const float cosine{ std::cos(angle) };
		graphicSound.setPosition(graphicListener.getPosition() + sf::Vector2f(sine * graphicOrbitDistance, -cosine * graphicOrbitDistance));
		sound.setPosition(sine, 0.f, -cosine);
		window.clear();
		window.draw(graphicListener);
		window.draw(graphicSound);
		window.display();
	}
#endif // SHOW_INTERACTIVE_VISUALISATION

	return EXIT_SUCCESS;
}
