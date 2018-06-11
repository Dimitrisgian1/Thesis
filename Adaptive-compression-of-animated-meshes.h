#include <VVRScene/canvas.h>
#include <VVRScene/mesh.h>
#include <VVRScene/settings.h>
#include <VVRScene/utils.h>
#include <MathGeoLib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Eigen/Dense>

class Mesh3DScene : public vvr::Scene
{
public:
    Mesh3DScene();
    const char* getName() const { return "3D Scene"; }

private:
    void draw() override;
    void reset() override;
    void resize() override;

private:
    vvr::Canvas2D m_canvas;
    vvr::Colour m_obj_col;
    vvr::Mesh m_model_original[175], m_model;
};
