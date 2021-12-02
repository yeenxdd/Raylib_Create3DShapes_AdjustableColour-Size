/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera mode
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");

    //GUI controls initialization
    int width = 200;
    int height = 100;
    bool drawCube=false;
    bool drawSphere=false;
    bool drawCuboid=false;


    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    //shapes size     
    Vector3 cubeSize = {2.0f,2.0f,2.0f};
    int sphereSize = 1.0f; //sphere radius, ring,slice
    Vector3 cuboidSize = {2.0f,3.0f,4.0f};

    
    //shapes position
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    Vector3 spherePosition = { 3.0f, 0.0f, 0.0f };
    Vector3 cuboidPosition = { -3.0f, 0.0f, 0.0f };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        Rectangle rec = { (GetScreenWidth() - width - 250)/2, (GetScreenHeight() - height)/2, width, height }; //gui controls rec position
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            //Draw GUI controls
            drawCube=GuiCheckBox((Rectangle){ 640, 80, 20, 20 }, "Cube", drawCube);
            drawSphere=GuiCheckBox((Rectangle){ 640, 110, 20, 20 }, "Sphere", drawSphere);
            drawCuboid=GuiCheckBox((Rectangle){ 640, 140, 20, 20 }, "Cuboid", drawCuboid);


            BeginMode3D(camera);
            
                
                if(drawCube){
                    DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED);
                    DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, PINK);
                }
                
                if(drawSphere){
                    DrawSphere(spherePosition,sphereSize,BLUE);
                    DrawSphereWires(spherePosition,sphereSize,sphereSize,sphereSize,SKYBLUE);
                }
                
                if(drawCuboid){
                    DrawCube(cuboidPosition, cuboidSize.x, cuboidSize.y, cuboidSize.z, LIME);
                    DrawCubeWires(cuboidPosition,cuboidSize.x, cuboidSize.y, cuboidSize.z, GREEN);
                }

                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}