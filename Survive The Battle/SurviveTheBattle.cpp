#include <iostream>
#include <cstdlib> 
#include <ctime>   

int main() {
    srand(time(0));  

    int health = 100;
    int stamina = 100;
    int score = 0;
    int level = 1;
    bool hasPotion = false;

    std::cout << "You are a brave warrior on a quest to save your village from invading monsters.\n";

    while (health > 0) {
        std::cout << "\n--- Level " << level << " ---\n";
        std::cout << "Your current health: " << health << "\n";
        std::cout << "Your current stamina: " << stamina << "\n";

      
        int enemyType = rand() % 2;
        if (enemyType == 0) {
            std::cout << "A goblin appears!\n";
        }
        else {
            std::cout << "A dragon appears!\n";
        }

        std::cout << "What do you want to do?\n";
        std::cout << "1. Fight\n2. Run\n3. Search for a health potion\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            if (enemyType == 0) {  // Goblin
                std::cout << "You fought the goblin and lost 10 health.\n";
                health -= 10;
                score += 10;
            }
            else {  // Dragon
                std::cout << "You fought the dragon and lost 30 health.\n";
                health -= 30;
                score += 30;
            }
            stamina -= 20;  // Fighting costs stamina
        }
        else if (choice == 2) {
            std::cout << "You ran away safely but lost 10 stamina.\n";
            stamina -= 10;
        }
        else if (choice == 3) {
            int randomEvent = rand() % 2;  // 50% chance of finding a potion
            if (randomEvent == 0) {
                std::cout << "You found a health potion!\n";
                hasPotion = true;
            }
            else {
                std::cout << "You couldn't find any potion.\n";
            }
        }
        else {
            std::cout << "Invalid choice.\n";
        }

        // Option to use health potion if the player has one
        if (hasPotion) {
            std::cout << "Do you want to use the health potion? (1 for yes, 2 for no): ";
            std::cin >> choice;
            if (choice == 1) {
                health += 20;
                hasPotion = false;
                std::cout << "You used the health potion and gained 20 health.\n";
            }
        }

        // Check if the player has lost or won
        if (health <= 0) {
            std::cout << "Game Over! You died.\n";
            break;
        }

        // Increase level after surviving
        level++;
        if (level == 10) {
            std::cout << "Congratulations! You reached level 10 and saved the village!\n";
            break;
        }

        // Rest and recover stamina after each level
        std::cout << "You rest for a while and recover 20 stamina.\n";
        stamina += 20;
    }

    std::cout << "Your final score: " << score << "\n";
    std::cout << "You reached level: " << level << "\n";

    return 0;
}
