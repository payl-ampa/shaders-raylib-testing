#include "raylib.h"

int main(void)
{
    const char* vert_shader_path = "lib/shaders/vert.glsl";
    const char* frag_shader_path = "lib/shaders/frag.glsl";

    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Shader shader = LoadShader(vert_shader_path , frag_shader_path);

    // Setup camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 10.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;           

    Model model = LoadModel("lib/models/stlgate.obj");                   // Load OBJ model

    Vector3 position = { 0.0f, 0.0f, 1.0f };    // Set model position
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawModel(model, position, 0.8f, WHITE);   // Draw 3d model with texture

                DrawGrid(10, 1.0f);     // Draw a grid

            EndMode3D();

            DrawText("(c) Watermill 3D model by Alberto Cano", screenWidth - 210, screenHeight - 20, 10, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadShader(shader);
    UnloadModel(model);

    CloseWindow();

    return 0;
}