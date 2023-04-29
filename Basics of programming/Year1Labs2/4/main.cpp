#include <conio.h>
#include <vector>
#include<algorithm>
#include "circle.h"
#include "rectangle.h"


int main() {
    std::vector<IGeoFig*> figures;

    while(true) {
        std::cout << "Press key to: \n";
        std::cout << "1) Add figure\n";
        std::cout << "2) Show all figures\n";
        std::cout << "3) The total area of all figures\n";
        std::cout << "4) The total perimeter of all figures\n";
        std::cout << "5) The center of mass of the entire system\n";
        std::cout << "6) The memory occupied by all instances of classes\n";
        std::cout << "7) Sorting shapes among themselves by weight\n";
        int input;
        input = getch();
        switch (input) {
            case '1':
                std::cout << "Press 1 to add circle\n";
                std::cout << "Press 2 to add rectangle\n";
                int in;
                in = getch();
                switch(in) {
                    case '1':
                        figures.push_back(new Circle);
                        break;
                    case '2':
                        figures.push_back(new Rectangle);
                        break;
                    default:
                        std::cout << "Wrong command...\n";
                        break;
                }
                figures.back()->initFromDialog();
                break;
            case '2':
                for (const auto& it : figures) {
                    it->draw();
                }
                break;
            case '3': {
                double total_area = 0;
                for (const auto &it: figures) {
                    total_area += it->square();
                }
                std::cout << total_area << '\n';
                break;
            }
            case '4': {
                double total_perimeter = 0;
                for (const auto &it: figures) {
                    total_perimeter += it->perimeter();
                }
                std::cout << total_perimeter << '\n';
                break;
            }
            case '5': {
                double all = 0;
                double x = 0;
                double y = 0;
                CVector2D centre;
                for (const auto &figure: figures) {
                    x += figure->position().x * figure->mass();
                    y += figure->position().y * figure->mass();
                    all += figure->mass();
                }
                centre.x = x / all;
                centre.y = y / all;
                std::cout << centre.x << ' ' << centre.y << '\n';
                break;
            }
            case '6': {
                size_t memory = 0;
                for (const auto& it : figures) {
                    memory += it->size();
                }
                std::cout << memory << '\n';
                break;
            }
            case '7':
                std::sort(figures.begin(), figures.end(), [](IGeoFig* a, IGeoFig* b) { return a->mass() < b->mass(); });
                for (const auto& it : figures) {
                    std::cout << it->classname() << ": " << it->mass() << '\n';
                }
                break;
            default:
                std::cout << "Wrong command... Try again\n";
                break;
        }
    }
}