// Critter 2.0.cpp
//www.github.com/ryswint

#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void GetLevels();

private:
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
    int GetHunger();
    int GetBoredom();
    void Reason();
};

Critter::Critter(int hunger, int boredom) :
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}
void Critter::Talk()
{
    cout << "I'm a critter and I feel ";
    int mood = GetMood();
    if (mood > 15)
    {
        cout << "mad, ";
    }
    else if (mood > 10)
    {
        cout << "frustrated, ";
    }
    else if (mood > 5)
    {
        cout << "okay, ";
    }
    else
    {
        cout << "happy, ";
    }
    Reason();
    PassTime();
}

void Critter::Reason()
{
    cout << "because ";
    if (m_Boredom > 8)
    {
        cout << "I'd literally kill for something to do ";
    }
    else if (m_Boredom > 5)
    {
        cout << "I'm bored as hell ";
    }
    else if (m_Boredom > 3)
    {
        cout << "I'm a little bored ";
    }
    else
    {
        cout << "I'm entertained ";
    }
    cout << "and ";

    if (m_Hunger > 8)
    {
        cout << "literally kill for something to eat!";
    }
    else if (m_Hunger > 5)
    {
        cout << "pretty hungry.";
    }
    else if (m_Hunger > 3)
    {
        cout << "getting a bit peckish.";
    }
    else
    {
        cout << "gotta full belly!";
    }
}

void Critter::Eat(int food)
{
    cout << "Brrupp.\n";

    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::GetLevels()
{
    cout << "\nDEBUG:" << endl;
    cout << "m_Hunger= " << GetHunger() << endl;
    cout << "m_Boredom= " << GetBoredom() << endl;
}

int Critter::GetHunger()
{
    return m_Hunger;
}

int Critter::GetBoredom()
{
    return m_Boredom;
}

int main()
{
    Critter crit;
    crit.Talk();

    int choice;
    do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Good-bye,\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 9:
            crit.GetLevels();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }

    } while (choice != 0);
    return 0;
}

