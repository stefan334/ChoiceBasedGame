#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include "player.h"

using namespace std;

struct enemy
{
    char name[20];
    float hp;
    int damage;
    char spell_1_name[20];
    bool spell_2_name[20];
    int spell_2_damage;
};

void choice_1(bool opt[10],player x)
{
    char answer[20];
    for(;;)
    {
        scanf("%30[^\n]s",answer);
        if(strcmp(answer,"help")==0)
        {
            opt[0]=1;
            break;
        }
        else if(strcmp(answer,"close door")==0)
        {
            opt[1]=1;
            break;
        }
        else
            cout<<"YOU CAN'T DO THAT! Try one of the options above \n";
        fflush(stdin);
    }
    if(opt[0]==1)
    {
        x.get_name();
        cout<<": Show me where you've last seen her.";
        cout<<endl;

        cout<<"You follow the young boy to the meadow in which they were playing earlier. You can clearly see the ogres footprints in the laid down grass";
        cout<<endl<<"(what do you do)"<<endl<<"*options: follow tracks, talk to kid"<<endl;

    }
}

void choice_2(bool opt[10],player x,bool iteme[10])
{
    char answer[20];
    for(;;)
    {
        scanf("%30[^\n]s",answer);
        fflush(stdin);
        if(strcmp(answer,"follow tracks")==0)
        {
            opt[0]=1;
            break;
        }
        else if(strcmp(answer,"talk to kid")==0)
        {
            opt[1]=1;
            break;
        }
        else
            cout<<"YOU CAN'T DO THAT! Try one of the options above \n";
        fflush(stdin);
    }
    if(opt[0]==1)
    {
        cout<<endl;
        cout<<"Kid: 'I'll stay behind so i dont get in your way, but please make sure you save my sister. I ll wait by your house please be quick'"<<endl;
        cout<<"You follow the tracks until you reach a cave; hiding behind a bush you notice an ogre at the entrance and some boxes laid around. You ask yourself if maybe there's more ogres inside the cave."<<endl;
        cout<<"(what do you do?)"<<endl<<"*options:draw sword and charge, hide behind boxes and enter cave, distract ogre*";
    }
    if(opt[1]==1)
    {
        cout<<"You tell the kid that he should stay behind and wait by your house until you come back with your sister. He begs of you to be quick.";
        srand(time(0));
        cout<<endl;
        if(1+(rand()%12)>=4)
        {
            cout<<"The boy asks you to hold your hand forwards; he gives you a bracelet. 'Please take this. I have it from my mother. It's supposed to protect me, i hope it works on you as well\n"<<endl;
            iteme[0]=1;
        }
        cout<<"You follow the tracks until you reach a cave; hiding behind a bush you notice an ogre at the entrance and some boxes laid around. You ask yourself if maybe there's more ogres inside the cave."<<endl;
        cout<<"(what do you do?)"<<endl<<"*Options:draw sword and charge, hide behind boxes and wait, distract ogre*"<<endl;
    }
}

void clear_opt(bool opt[10])
{
    for(int i=0; i<10; i++)
        opt[i]=0;
}
void enemy_act(struct enemy* enem, struct player* x,int* ok,int* charge,int dodge)
{

      if(x->player_hp<=enem->damage)
      {    if(dodge==1)
          cout<<"You dodge the enemy's attack"<<endl;
          else{
        x->player_hp-=enem->damage;
        printf("The Ogre deals %d damage to you. \n",enem->damage);}

      }else
      if(strcmp(enem->name,"Ogre")==0)
      {
          if(enem->hp<=50&&*ok==1)
          {   if(dodge==1)
              cout<<"You dodge the enemy's attack"<<endl;
              *ok=0;
              cout<<"The Ogre becomes enraged. His damage grows by 10"<<endl;
              enem->damage+=10;
          }else
          if(1+rand()%100<=40&&*charge==0)
          {
              cout<<"The Ogre prepares for a heavy attack"<<endl;
              cout<<"The Ogre's next attack will do extra damage"<<endl;
              *charge=1;

          }else if(*charge==1)
          {
              if(dodge==1)
                    cout<<"The Ogre launches a heavy attack, but you manage to dodge it"<<endl;

          else{
              printf("The Ogre launches a heavy attack, dealing %d damage to you.\n",enem->damage*2);
              x->player_hp-=enem->damage*2;}
              *charge=0;
          }
          else{
                if(dodge==1)
                cout<<"You dodge the enemy's attack"<<endl;
          else{
          x->player_hp-=enem->damage;
          printf("The Ogre deals %d damage to you. \n",enem->damage);}
          }
      }


}
int fight(struct enemy enem,struct player x,bool iteme[10],bool opt[10])
{
    int ok=1,charge=0,dodge=0,cd=0;
    char answer[20];
    cout<<"\n FIGHT!\n";
    printf("Your opponent has %f HP \n",enem.hp);
    float b=enem.hp;
    while(enem.hp > 0 && x.player_hp > 0)
    {

        cout<<"What Do You Do? \n *Options: Slash, Dodge, Use item* \n";
        for(;;)
        {
            scanf("%20[^\n]s",answer);
            if(strcmp(answer,"slash")==0)
            {
                opt[0]=1;
                break;
            }
            else if(strcmp(answer,"dodge")==0&&cd==0)
            {
                opt[1]=1;
                break;
            }
            else if(strcmp(answer,"use item")==0)
            {
                opt[2]=1;
                break;
            }
            else
                cout<<"YOU CAN'T DO THAT! Try one of the options above \n";
                fflush(stdin);

        }
        fflush(stdin);
        if(opt[0]==1)
        {

                printf("What part of the %s do you want to attack?\n *Options: Body, Head, Arm* \n",enem.name);
                for(;;)
                {
                    scanf("%20[^\n]s",answer);
                    if(strcmp(answer,"body")==0)
                    {
                        opt[3]=1;
                        break;
                    }
                    else if(strcmp(answer,"head")==0)
                    {
                        opt[4]=1;
                        break;
                    }
                    else if(strcmp(answer,"arm")==0)
                    {
                        opt[5]=1;
                        break;
                    }
                    else
                        cout<<"YOU CAN'T DO THAT! Try one of the options above \n";
                        fflush(stdin);
                }// sf for optiuni zona atac

                if(opt[3]==1)
                {
                    enem.hp=enem.hp-x.player_dmg;
                    // Aici trebuie sa pui damageu playerului si sa iei in considerare niste optiuni cu rand gen ratat inamicu blocheaza il tai etc
                }
                else if(opt[4]==1)
                {
                    int a=1+rand()%10;
                    if((enem.hp<=b*0.2) && (a>=2) )
                    {
                        printf(" You Manage to chop off the %s's head. His lifeless body falls down\n",enem.name);
                        enem.hp=0;
                    }
                    else
                        if(a<6)
                            {printf("You try to chop off his head, but fail and only inflict a minor wound onto the enemy. You deal %f\n",x.player_dmg*0.2);
                                enem.hp-=x.player_dmg*0.2;}
                                else
                        if(enem.hp>b*0.2)
                           {
                            printf("You try to chop off his head, but fail due to the fact that the enemy's hp is not low enough. You deal %f\n",x.player_dmg*0.2);
                        enem.hp-=x.player_dmg*0.2;}

                } //sf if pt cap
                else if(opt[5]==1) // daca ataci brat
                {
                    int a=1+rand()%10;
                    if(enem.hp<=b*0.6 && a>=4)
                    {
                        printf(" You manage to chop off %s's arm. His damage has been decreased by 40 percent \n",enem.name);
                        printf("You also deal %d damage to him\n",x.player_dmg*0.7);
                        enem.hp-=x.player_dmg*0.7;
                        enem.damage=enem.damage*0.6;
                    }
                    else if(a<4)
                    {
                        printf("You try to chop off his arm, but only manage to inflict a minor wound onto the enemy. You deal %f\n",x.player_dmg*0.7);
                        enem.hp-=x.player_dmg*0.7;
                    }
                    else if(enem.hp>b*0.6)
                    {
                        printf("You try to cut off his arm, but fail due to the fact that the enemy's hp is not low enough. You deal %f\n",x.player_dmg*0.7);
                        enem.hp-=x.player_dmg*0.7;
                    }

                }//sf if atac brat





        }
        else if(opt[1]==1&&cd==0)  //optiune de DODGE
        {
              //+ COOLDOWN + Counterattack 20%

            dodge=1;
            cd=3;
        }
        else if(opt[2]==1)
        {
            for(;;)
            {
                cout<<"What item would you like to use?";
            }
        }
        fflush(stdin);
       opt[0]=0;opt[1]=0;opt[2]=0;opt[3]=0;opt[4]=0;opt[5]=0;
        if(cd>0){
        cd--;
        printf("You cant dodge for %d more turn\n",cd);}
        if(enem.hp>0)
        enemy_act(&enem,&x,&ok,&charge,dodge);
        if(((dodge==1)&&(1+rand()%100<=30))&&charge==0)
        {
            printf("You manage to counter-attack the %s. You deal %d damage to him.\n",enem.name,x.player_dmg/2);
            enem.hp-=x.player_dmg/2;
        }
        dodge=0;
        printf("\n%s has %f HP left\n\n",enem.name,enem.hp);
        printf("You have %d HP left\n\n",x.player_hp);
    }
    return x.player_hp;
}
void choice_3(bool opt[10],struct player x,bool iteme[10],struct enemy enem)
{
    char answer[20];
    printf("\n");
    for(;;)
    {
        scanf("%30[^\n]s",answer);
        fflush(stdin);
        if(strcmp(answer,"draw sword and charge")==0)
        {
            opt[0]=1;
            break;
        }
        else if(strcmp(answer,"hide behind boxes and wait")==0)
        {
            opt[1]=1;
            break;
        }
        else if(strcmp(answer,"distract ogre")==0)
        {
            opt[2]=1;
            break;
        }
        else
            cout<<"YOU CAN'T DO THAT! Try one of the options above \n";
        fflush(stdin);
    }
    if(opt[0]==1)
    {
        clear_opt(opt);
        x.player_hp=fight(enem,x,iteme,opt);
        cout<<x.player_hp;
        opt[0]=1;
    }

}


int main()
{

    char answer[20];
    bool iteme[10]= {0}; //vector de iteme 0) bracelet of revival
    bool opt[10]= {0};
    bool alegeri[10]= {0}; //vector de alegeri
    cout<<"Welcome to the game... Please enter your name: ";
    player a;
    a.player_dmg=20;
    a.player_hp=100;
    cout<<"You wake up to loud knocking on your door. You dont usually have visitors since you live in a cabin in the woods."<<endl<<"You go to the door and open it. Its a young boy."<<endl;
    cout<<"(Press enter to continue)";
    cin.ignore();
    cin.ignore();
    cout<<"'Help me mister please help me. My sister, she's been kidnapped by a huge ogre while we were in a meadow in the forest. I need your help!!'";
    cout<<endl;
    cout<<"(what do you do?)"<<endl<<"*options: help, close door*"<<endl;
    choice_1(opt,a);
    fflush(stdin);
    clear_opt(opt);
    choice_2(opt,a,iteme);
    fflush(stdin);
    clear_opt(opt);
    struct enemy enem;
    enem.damage=10;
    enem.hp=100;
    strcpy(enem.name,"Ogre");
    choice_3(opt,a,iteme,enem);
    // functia de fight si de a 3a optiune care i lunga ca pl
   cin.ignore();
   cin.ignore();
    return 0;
}
