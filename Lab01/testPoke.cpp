
char end = 'n';

do
{
Pokemon player1;
Pokemon player2;
Colosseum c;
std::cout << "Player 1 build your Pokemon!\n";
std::cout << "=====================\n";
c.userBuild(player1);

std::cout << "Player 2 build your Pokemon!\n";
std::cout << "=====================\n";
c.userBuild(player2);

c.play(player1, player2);

std::cout << "Do you want to play again (y/n)? ";
std::cin >> end;
std::cout << "\n\n";
}while (end!='n');





if (turn == 1 && dead==false)
{
    std::cout << "\nRound " << round << "!\n";
    dead= attack(p1, p2);

    if (dead==false)
    {
        dead=attack(p2, p1);
        if (dead==true)
        {
            std::cout << p1.getName() << " has been defeated!";
            dead=true;
        }
    }
    else
    {
        std::cout << p2.getName() << " has been defeated!";
    }

}


if (turn != 1 && dead == false)
{
    std::cout << "\nRound " << round << "!\n";
    dead= attack(p2, p1);

    if (dead==false)
    {
        dead=attack(p1, p2);
        if (dead==true)
        {
        std::cout << p2.getName() << " has been defeated!";
        dead=true;
        }
    }
}
else
{
    std::cout << p1.getName() << " has been defeated!";
}

round++;
}
