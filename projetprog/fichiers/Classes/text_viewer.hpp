//
//  text_viewer.hpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 29.04.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//
#ifndef TEXT_VIEWER_H
#define TEXT_VIEWER_H

#include <iostream>
#include "SupportADessin.hpp"
#include"Source.hpp"
#include "Plan.hpp"
#include "Portion_Plan.hpp"
#include "Systeme.hpp"
#include "Brique.hpp"
#include "Cylindre.hpp"

class TextViewer : public SupportADessin {
public:
    TextViewer(std::ostream& flot);
    
    virtual ~TextViewer();
    
    virtual void dessine(Grain const& a_dessiner)  override;
    virtual void dessine(Source const& a_dessiner) override;
    virtual void dessine(Plan const& a_dessiner)  override;
    virtual void dessine(Systeme const& a_dessiner) override;
    virtual void dessine(Brique const& a_dessiner) override;
    virtual void dessine(Cylindre const& a_dessiner) override;
    virtual void dessine(PortionPlan const& a_dessiner) override;
    virtual void dessine(Sphere const& a_dessiner) override;
    
private:
    std::ostream& flot;
};

#endif  /* text_viewer_hpp */
