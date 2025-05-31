
#ifndef __PROCESSMODEL_H
#define __PROCESSMODEL_H

#include "world.hpp"
#include <io.h>
#include <stdio.h>
#include <wtypes.h>

// External global variables used for model processing and scene rendering.
// Note: Extensive use of global variables can make code harder to maintain.
extern int monstercull[1000];
extern int monstercount;
extern float fDot2;
extern int weapondrop;
extern int obdata_length;
extern int oblist_length;
extern int *num_vert_per_object;
extern int num_polys_per_object[500];
extern int num_triangles_in_scene;
extern int num_verts_in_scene;
extern int num_dp_commands_in_scene;
extern int cnt;

// Converts indexed player model data (e.g., 3DS) to a vertex list.
void PlayerToD3DIndexedVertList(int pmodel_id, int curr_frame, float angle,
                                int texture_alias, int tex_flag, float xt,
                                float yt, float zt);
// Finds the model ID for a given model name.
int FindModelID(const char *p);
// Adds a static model instance to the game world.
void AddModel(float x, float y, float z, float rot_angle, float monsterid,
              float monstertexture, float monnum, char modelid[80],
              char modeltexture[80], int ability);
// Finds the texture ID for a given gun name.
int FindGunTexture(const char *p);
// Cycles through animated texture frames (e.g., name@1, name@2).
int CycleBitMap(int i);
// Determines if a point is within the viewing frustum/angle.
int CalculateView(XMFLOAT3 EyeBall, XMFLOAT3 LookPoint, float angle);
// Converts a general game object to a vertex list.
void ObjectToD3DVertList(int ob_type, float angle, int oblist_index);

#endif