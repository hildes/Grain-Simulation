//
//  text_viewer.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 29.04.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "text_viewer.h"

#include <iostream> // pour endl


void TextViewer::dessine(Grain const& a_dessiner){
    flot<<a_dessiner<<std::endl;
}
void TextViewer::dessine(Source const& a_dessiner){
    flot<<a_dessiner<<std::endl;
}
void TextViewer::dessine(Plan const& a_dessiner){
    flot<<a_dessiner<<std::endl;
}

void TextViewer::dessine( Systeme const& a_dessiner)
{
    for (auto grain : a_dessiner.get_Grain() )
    {
        flot<< grain<<std::endl;
    }
}

