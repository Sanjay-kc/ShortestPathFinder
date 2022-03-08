#include"GUI.hpp"

std::string IntToString(int a)
{
    std::ostringstream temp;
    temp << a;
    return temp.str();
}


GUI::GUI()
    {
        window.create(sf::VideoMode(1200,700),"Dijkhstra's shortest path algorithm");
        window.setPosition(sf::Vector2i(40,0));
        if (!font.loadFromFile("FiraMono-Regular.otf"))
      {
       std::cout<<"error";
      }

    }

int GUI::start()
{
    int status=1;
    int startkey=0;
    sf::Text text;

    text.setFont(font);
    text.setString("Press E to start");

    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(500,350);

     while (window.isOpen())
    {
     sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
               {
                   status=0;
                   window.close();

               }

             if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode==69 || event.text.unicode==101)
                {
                    startkey=1;
                    break;
                }

            }

//if e entered break loop
        }

        window.clear(sf::Color(255, 255, 255));
        window.draw(text);
        window.display();

        if (startkey==1)
        break;


    }
    return status;

    }


int GUI::drawnodes()
{
    int stop=0;
    sf::RectangleShape go(sf::Vector2f(60,30));
   // go.setFillColor(sf::Color(0,255,0));
    go.setFillColor(sf::Color::Green);
    go.setPosition(1020,640);
    //if that clicked stop drawing nodes
    sf::Text text1,text2;
    text1.setFont(font);
    text1.setString("Click to make a node");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(930,675);

    text2.setFont(font);
    text2.setString("GO");
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(1030,635);

     while (window.isOpen())
    {
     sf::Event event;
        while (window.pollEvent(event))
        {
            int overlap=0,offfield=0;
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
               {
                   window.close();
               }

             if (event.type == sf::Event::MouseButtonPressed)
            {

                sf::IntRect ButtonRect;
                sf::Vector2i mouse=sf::Mouse::getPosition(window);
                ButtonRect=sf::IntRect(go.getPosition().x, go.getPosition().y, go.getGlobalBounds().width, go.getGlobalBounds().height);

                if (ButtonRect.contains(mouse))
                {
                    stop=1;
                    break;
                }

                for (int i=0;i<no_of_nodes;i++)
                {
                    ButtonRect=sf::IntRect(node[i].getPosition().x, node[i].getPosition().y, node[i].getGlobalBounds().width*2, node[i].getGlobalBounds().height*2);

                    if (ButtonRect.contains(mouse))
                    {
                        overlap=1;
                        break;
                    }
                }

                ButtonRect=sf::IntRect(text1.getPosition().x, text1.getPosition().y, text1.getGlobalBounds().width, text1.getGlobalBounds().height);
                if (ButtonRect.contains(mouse))
                {
                    overlap=1;
                    break;
                }

                if((mouse.x<40) || (mouse.y<40) || (mouse.x>1160) ||( mouse.y>660))
                {
                    offfield=1;
                }



                if (overlap || offfield)
                    continue;

                if(no_of_nodes<10)
                {
                    node[no_of_nodes].setRadius(40);
                    node[no_of_nodes].setFillColor(sf::Color::Black);
                    node[no_of_nodes].setPosition(mouse.x-40,mouse.y-40);
                    //  string s=string
                    std::string s=IntToString(no_of_nodes+1);

                    nodenum[no_of_nodes].setString(s);
                    nodenum[no_of_nodes].setFont(font);
                    nodenum[no_of_nodes].setCharacterSize(30);
                    nodenum[no_of_nodes].setColor(sf::Color::White);
                    nodenum[no_of_nodes].setPosition(mouse.x-10,mouse.y-15);

                    position[no_of_nodes][0]=mouse.x;
                    position[no_of_nodes][1]=mouse.y;

                    no_of_nodes++;

                }
		    }


        }

        window.clear(sf::Color(255,255,255));
        //draw nodes
        for (int k=0;k<no_of_nodes;k++)
        {
            window.draw(node[k]);
        }
        for (int k=0;k<no_of_nodes;k++)
        {
            window.draw(nodenum[k]);
        }

        if(stop)
         break;

        window.draw(text1);
        window.draw(go);
        window.draw(text2);
        window.display();


    }
    return no_of_nodes;
}


 void  GUI::inputWeight(int** weight)
{
    int returnstatus=0;
    sf::RectangleShape answer(sf::Vector2f(100,40));
   // go.setFillColor(sf::Color(0,255,0));
    answer.setFillColor(sf::Color::Black);
    answer.setPosition(1020,640);

    sf::RectangleShape go(sf::Vector2f(60,30));
   // go.setFillColor(sf::Color(0,255,0));
    go.setFillColor(sf::Color::Green);
    go.setPosition(1020,640);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("GO");
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(1030,635);

    wt=new sf::Text*[no_of_nodes];
    for (int i=0;i<no_of_nodes;i++)
    {
        wt[i]=new sf::Text[no_of_nodes];
    }

    for (int i=0;i<no_of_nodes;i++){
        for (int j=0;j<no_of_nodes;j++)
        {
            wt[i][j].setFont(font);
            wt[i][j].setCharacterSize(30);
            wt[i][j].setFillColor(sf::Color::White);
            wt[i][j].setPosition(0,0);
        }
    }

    x=new float*[no_of_nodes];
    for (int i=0;i<no_of_nodes;i++)
    {
        x[i]=new float[no_of_nodes];
    }

    y=new float*[no_of_nodes];
    for (int i=0;i<no_of_nodes;i++)
    {
        y[i]=new float[no_of_nodes];
    }
//
//        link = new int*[no_of_nodes];
//        for(int i = 0; i < no_of_nodes; ++i)
//        link[i] = new int[2];

    int askweight=0;

    line=new sf::RectangleShape*[no_of_nodes];
    for (int i=0;i<no_of_nodes;i++)
    {
        line[i]=new sf::RectangleShape[no_of_nodes];
    }

    for(int i=0;i<no_of_nodes-1;i++)
    {
        for (int j=i+1;j<no_of_nodes;j++)
        {
            //dist=((x2-x1)2+(y2-y1)2)1/2
            // std::cout<<position[j][0]<<" "<<position[i][0]<<" "<<position[j][1]<<" "<<position[i][1]<<std::endl;
            x[i][j]=position[j][0]-position[i][0];
            y[i][j]=position[j][1]-position[i][1];
            //  std::cout<<x[i][j]<<" "<<y[i][j]<<" "<<std::endl;
            float distance=pow(pow(x[i][j],2)+pow(y[i][j],2),0.5);
            double angle=atan(fabs(y[i][j]/x[i][j]));
            angle=angle*180/3.1415;
            // std::cout<<angle;
            if(x[i][j]>0 && y[i][j]>0)
                angle=angle;
            if((x[i][j]>0) && (y[i][j]<0))
                angle=-angle;
            if(x[i][j]<0 && y[i][j]>0)
                angle=180-angle;
            if(x[i][j]<0 && y[i][j]<0)
                angle=-180+angle;
            // std::cout<<angle<<std::endl;

            line[i][j].setSize(sf::Vector2f(distance-30.f, 7.f));
            line[i][j].setFillColor(sf::Color::Transparent);
            line[i][j].setPosition(position[i][0],position[i][1]);
            line[i][j].rotate(angle);

        }
        // std::cout<<"okay fr i end"<<std::endl;
    }

    int nodeclicked[2];
    int click1=0,click2=0,waiting=0;
    int num=0;

    while (window.isOpen())
    {
        sf::Event event;
        if (click1!=0 &&  click2!=0)
                {
                    click1=0;
                    click2=0;
                }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if (event.type == sf::Event::TextEntered && askweight)
            {
                if (event.text.unicode>47 && event.text.unicode<58)
                {
                    num=num*10+(event.text.unicode-48);

                }
            }


            if (event.type == sf::Event::MouseButtonPressed)
            {
            sf::IntRect ButtonRect;
            sf::Vector2i mouse=sf::Mouse::getPosition(window);

            if(askweight==0)
            {
            ButtonRect=sf::IntRect(go.getPosition().x, go.getPosition().y, go.getGlobalBounds().width*2, go.getGlobalBounds().height*2);
            if (ButtonRect.contains(mouse))
            {
                returnstatus=1;
                break;
            }
            }

            if (askweight)
            {
            ButtonRect=sf::IntRect(answer.getPosition().x, answer.getPosition().y, answer.getGlobalBounds().width*2, answer.getGlobalBounds().height*2);
            if (ButtonRect.contains(mouse))
            {
                num=0;
                float wtplacex=position[nodeclicked[0]][0]+(x[nodeclicked[0]][nodeclicked[1]]/2.f);
                float wtplacey=position[nodeclicked[0]][1]+(y[nodeclicked[0]][nodeclicked[1]]/2.f);

                //   std::cout<<wtplacex<<" "<<wtplacey<<std::endl;

                wt[nodeclicked[0]][nodeclicked[1]].setPosition(wtplacex,wtplacey);
                wt[nodeclicked[0]][nodeclicked[1]].setFillColor(sf::Color::Black);
                askweight=0;
    //            for(int i=0;i<no_of_nodes-1;i++)
    //            {
    //            for(int j=i+1;j<no_of_nodes;j++)
    //            {
    //              std::cout<<weight[i][j]<<std::endl;
    //            }
    //            }
                break;

            }
            }

            else{
            for (int i=0;i<no_of_nodes;i++)
            {
            ButtonRect=sf::IntRect(node[i].getPosition().x, node[i].getPosition().y, node[i].getGlobalBounds().width*2, node[i].getGlobalBounds().height*2);

            if (ButtonRect.contains(mouse))
            {
                if (click1==0 && click2==0)
                {
                click1=1;
                nodeclicked[0]=i;
                break;
                }


                if (click1!=0 && click2==0)
                {
                    click2=1;
                    nodeclicked[1]=i;
                    break;
                }

            }


            }
            }


        }
        }

        if (click1!=0 and  click2!=0)
        {
        int temp;
        if (nodeclicked[0]>nodeclicked[1])
        {
            temp=nodeclicked[0];
            nodeclicked[0]=nodeclicked[1];
            nodeclicked[1]=temp;
        }


        //find baseIndex
        line[nodeclicked[0]][nodeclicked[1]].setFillColor(sf::Color(211,211,211));
        askweight=1;
        wt[nodeclicked[0]][nodeclicked[1]].setPosition(1030,635);
        }


        window.clear(sf::Color(255, 255, 255));
        for(int i=0;i<no_of_nodes-1;i++)
        {
            for(int j=1;j<no_of_nodes;j++)
            {
            window.draw(line[i][j]);
            }
        }

        for (int k=0;k<no_of_nodes;k++)
        {
        window.draw(node[k]);
        }
        for (int k=0;k<no_of_nodes;k++)
        {
            window.draw(nodenum[k]);
        }

            if (askweight==1)
        {
            std::string s=IntToString(num);
            wt[nodeclicked[0]][nodeclicked[1]].setString(s);
            window.draw(answer);
            weight[nodeclicked[0]][nodeclicked[1]]=num;
        }

        if (askweight==0)
        {
            window.draw(go);
            window.draw(text2);
        }


        for(int i=0;i<no_of_nodes-1;i++)
        {
            for(int j=i+1;j<no_of_nodes;j++)
            {
                window.draw(wt[i][j]);
            }
        }

        window.display();
            if (returnstatus==1)
            break;
    }
}



 int GUI::display()
    {
    sf::Clock clock;
    int returnstatus=0;
    int stand=1;
    sf::Time delay=sf::seconds(2.f);
    while (window.isOpen())
    {
     sf::Time time=clock.getElapsedTime();
     sf::Event event;
        while (window.pollEvent(event))
        {
             if (event.type == sf::Event::Closed)
               {
                   stand=0;
                   window.close();
               }
        }
            if (time.asSeconds()>delay.asSeconds())
            {
                returnstatus=1;
                break;
            }


        window.clear(sf::Color(255, 255, 255));
        for(int i=0;i<no_of_nodes-1;i++)
        {
            for(int j=1;j<no_of_nodes;j++)
            {
            window.draw(line[i][j]);
            }
        }

        for (int k=0;k<no_of_nodes;k++)
        {
        window.draw(node[k]);
        }

        for (int k=0;k<no_of_nodes;k++)
        {
         window.draw(nodenum[k]);
        }

        for(int i=0;i<no_of_nodes-1;i++)
        {
            for(int j=i+1;j<no_of_nodes;j++)
            {
                window.draw(wt[i][j]);
            }
        }

        window.display();
        if (returnstatus==1 || (stand==0))
            break;
    }

    return stand;
}

    void GUI::update(int nodeno,int precede )
    {
        //smaller in nodeno and greater in precede
        node[nodeno].setOutlineThickness(10);
        node[nodeno].setOutlineColor(sf::Color(250, 150, 100));
        if(nodeno>precede)
        {
            int temp=nodeno;
            nodeno=precede;
            precede=temp;
        }

        line[nodeno][precede].setFillColor(sf::Color(100,100,100));

        std::cout<<nodeno<<" "<<precede<<std::endl;
        //change line colour ,precede to nodeno, small in i and bigger in j
        //set outline of the the circle of nodeno

    }

// int GUI::selectSource(){
//     int stop=0,s=0;
//     sf::Text text1;
//     text1.setFont(font);
//     text1.setString("Select the source node");
//     text1.setCharacterSize(20);
//     text1.setFillColor(sf::Color::Black);
//     text1.setPosition(930,675);
//     while (window.isOpen())
//     {   
//         window.draw(text1);
//         sf::Event event;
//         while (window.pollEvent(event))
//         {   
//             int overlap=0,offfield=0;
//             // "close requested" event: we close the window
//             if (event.type == sf::Event::Closed)
//                {
//                    window.close();
//                }

//              if (event.type == sf::Event::MouseButtonPressed)
//             {

//                 sf::IntRect ButtonRect;
//                 sf::Vector2i mouse=sf::Mouse::getPosition(window);

//                 for (int i=0;i<no_of_nodes;i++)
//                 {
//                     ButtonRect=sf::IntRect(node[i].getPosition().x, node[i].getPosition().y, node[i].getGlobalBounds().width*2, node[i].getGlobalBounds().height*2);

//                     if (ButtonRect.contains(mouse))
//                     {
//                         s=i;
//                         stop=1;
//                         break;
//                     }
//                 }

//                 ButtonRect=sf::IntRect(text1.getPosition().x, text1.getPosition().y, text1.getGlobalBounds().width, text1.getGlobalBounds().height);
//                 if (ButtonRect.contains(mouse))
//                 {
//                     overlap=1;
//                     break;
//                 }

//                 if((mouse.x<40) || (mouse.y<40) || (mouse.x>1160) ||( mouse.y>660))
//                 {
//                     offfield=1;
//                 }



//                 if (overlap || offfield)
//                     continue;

              

//             }
// 		}
//         if (stop)
//             break;
        

//     }
        
        


// }

