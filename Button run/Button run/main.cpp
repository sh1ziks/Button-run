#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	setlocale(0, "ru");

	RenderWindow window(VideoMode(640, 460), "Button Run");

	RectangleShape buttonYes(Vector2f(150, 50));
	buttonYes.setFillColor(Color::Black);
	buttonYes.setPosition(Vector2f((window.getSize().x / 2) * 0.25, (window.getSize().y / 3) * 2));

	RectangleShape buttonNo(Vector2f(150, 50));
	buttonNo.setFillColor(Color::Black);
	buttonNo.setPosition(Vector2f((window.getSize().x / 2) * 1.25, (window.getSize().y / 3) * 2));

	Font font;
	font.loadFromFile("font/CyrilicOld.ttf");

	Text yes("да", font, 50);
	yes.setFillColor(Color::White);
	yes.setPosition(Vector2f(buttonYes.getPosition().x + 50, buttonYes.getPosition().y - 15));

	Text no("нет", font, 50);
	no.setFillColor(Color::White);
	no.setPosition(Vector2f(buttonNo.getPosition().x + 40, buttonNo.getPosition().y - 15));

	Text question("..?", font, 50);
	question.setFillColor(Color(0, 0, 0));
	question.setPosition(Vector2f(window.getSize().x / 3, window.getSize().y / 4));

	Text ask("...", font, 50);
	ask.setFillColor(Color(0, 0, 0));
	ask.setPosition(Vector2f(window.getSize().x / 3, window.getSize().y / 4));


	srand(time(0));
	bool ok = false;

	while (window.isOpen())
	{
		Event event;
		Vector2i mousePosition = Mouse::getPosition(window);

		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
				{
					if (buttonYes.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						buttonYes.setFillColor(Color(255, 0, 0));
						ok = true;
					}
				}

			if (buttonNo.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
			{
				buttonNo.setPosition(rand() % 600, rand() % 420);
				no.setPosition(Vector2f(buttonNo.getPosition().x + 40, buttonNo.getPosition().y - 15));
			}
		}

		window.clear(Color::White);
		if (!ok)
		{
			window.draw(buttonYes);
			window.draw(yes);
			window.draw(buttonNo);
			window.draw(no);
			window.draw(question);
		}
		if (ok)
			window.draw(ask);
		window.display();
	}
}