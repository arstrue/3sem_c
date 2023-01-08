#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Ball
{
    float radius;
    sf::Vector2f position;
    sf::Vector2f velocity;
};


int main()
{
    srand(time(0));

    const int width = 1000;
    const int height = 800;
    const int n_balls = 100;

    // ��� �� �������
    const float delta_t = 0.1;

    // ������ ��������� ������ ����
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    // ����� ������������ ���������� ������ � �������
    window.setFramerateLimit(60);

    // ��� ��� sf::CircleShape �������� ����� ������, ������ ����� 1 ���������
    sf::CircleShape circle(50.0f);
    circle.setFillColor({ 200, 216, 200 });

    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].radius = 4 + rand() % 8;
        balls[i].position = { (float)(rand() % width), (float)(rand() % height) };
        balls[i].velocity = { (float)(rand() % 100 - 50), (float)(rand() % 100 - 50) };
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // � ������ ������� ��������� ���� �� ��������
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // �������� ������� ����� ������ ������
        window.clear(sf::Color::Black);

        for (int i = 0; i < n_balls; i++)
        {
            balls[i].position += balls[i].velocity * delta_t;

            /*
            if (balls[i].position.x < 0)
                balls[i].position.x += width;
            if (balls[i].position.x > width)
                balls[i].position.x -= width;
            if (balls[i].position.y < 0)
                balls[i].position.y += height;
            if (balls[i].position.y > height)
                balls[i].position.y -= height;
            */

            // ���������� 1 sf::CircleShape, ����� ���������� ��� ����
            circle.setRadius(balls[i].radius);
            // setOrigin - ����� ����� �������
            // �� ��������� ����� - � ����� ������� ���� �������
            // ������ ���� ������������� ����� � ������ ������
            // � ���������� �������, setPosition ������������� ��������� ������ ���, 
            // ����� ��� ����� ��� � ����� balls[i].position
            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);

            window.draw(circle);
        }

        // ���������� ���������� �������� ������ �� �����
        window.display();
    }

    return 0;
}