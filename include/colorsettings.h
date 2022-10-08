//this is the library for the color of the game, can be implemented as a
//singleton in the future
#pragma once
class ColorSettings{
    public:
    ColorSettings();
    float darkgreen[4] = {0.129412, 0.231373, 0.145098, 1.0};
    float green[4] = {0.227451, 0.376471,  0.290196, 1.0};
    float lightgreen[4] = {0.309804, 0.466667, 0.329412, 1.0};
    float sand[4] = {0.631373, 0.623529, 0.486275, 1.0};
    float lightbrown[4] = {0.46667, 0.454902, 0.309804, 1.0};
    float brown[4] = {0.466667, 0.360784, 0.309804, 1.0};
    float darkbrown[4] = {0.376471, 0.23173, 0.227451, 1.0};
    float purple[4] = {0.23137,0.129412,0.215687,1.0};
    float black[4] = {0.09196,0.054902,0.098039216,1.0};
    float darkpurple[4] = {0.184313,0.129412,0.231373,1.0};
    float lightpurple[4] = {0.262745, 0.227451, 0.376471,1.0};
    float darkblue[4] = {0.309804, 0.321569, 0.466667, 1.0};
    float blue[4] = {0.396078, 0.450980,0.549019,1.0};
    float lightblue[4] = {0.48627451, 0.58039216, 0.6313725, 1.0};
    float lighterblue[4] = {0.627451, 0.725490, 0.7294117, 1.0};
    float lightestblue[4] = {0.752941, 0.81961, 0.8,1.0};
};
