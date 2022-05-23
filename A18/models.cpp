// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

void makeModels() {
    //// M1 : Cube
    // Replace the code below, that creates a simple square, with the one to create a cube.

    int sideLenght = 2.0;
    float ox = -1.0, oy = -1.0, oz = -1.0;
    float lastx= ox,  lasty= oy,  lastz= oz;

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices components (umber of vertices)
    M1_vertices.resize(8);
        
    M1_vertices[0].pos = glm::vec3(lastx, lasty, lastz);
    M1_vertices[0].norm = glm::vec3(lastx, lasty, lastz);


    for(int i=0;i<7;i++){
        if(lastx == ox){
            if(lasty == oy){
                lasty = lasty + sideLenght;
            }else {
                lastx = lastx + sideLenght;
            }
        }else{
            if(lasty == oy){
                lastx = lastx - sideLenght;
                lastz = lastz + sideLenght;
            }else {
                lasty = lasty - sideLenght;
            }
        }
        
        M1_vertices[i+1].pos = glm::vec3(lastx, lasty, lastz);
        M1_vertices[i+1].norm = glm::vec3(1.0, 1.0, 1.0);
    
        
       
    }


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M1_indices.resize(3 * 12);

    // first triangle
    M1_indices[0] = 0;
    M1_indices[1] = 1;
    M1_indices[2] = 2;

    // second triangle
    M1_indices[3] = 2;
    M1_indices[4] = 3;
    M1_indices[5] = 0;

        
    // third triangle
    M1_indices[6] = 1;
    M1_indices[7] = 2;
    M1_indices[8] = 5;

    // fouth triangle
    M1_indices[9] = 2;
    M1_indices[10] = 6;
    M1_indices[11] = 5;

    M1_indices[12] = 0;
    M1_indices[13] = 4;
    M1_indices[14] = 3;

    M1_indices[15] = 3;
    M1_indices[16] = 4;
    M1_indices[17] = 7;

    M1_indices[18] = 4;
    M1_indices[19] = 5;
    M1_indices[20] = 6;

    M1_indices[21] = 6;
    M1_indices[22] = 7;
    M1_indices[23] = 4;

    M1_indices[24] = 0;
    M1_indices[25] = 1;
    M1_indices[26] = 5;

    M1_indices[27] = 5;
    M1_indices[28] = 0;
    M1_indices[29] = 4;
        
    M1_indices[30] = 3;
    M1_indices[31] = 2;
    M1_indices[32] = 6;

    M1_indices[33] = 6;
    M1_indices[34] = 3;
    M1_indices[35] = 7;

/*
    M1_vertices.resize(4);

    // first vertex of M1
    M1_vertices[0].pos  = glm::vec3(-1.0,-1.0,-1.0);
    M1_vertices[0].norm = glm::vec3(0.0,0.0,1.0);

    // second vertex of M1
    M1_vertices[1].pos  = glm::vec3(1.0,-1.0,-1.0);
    M1_vertices[1].norm = glm::vec3(0.0,0.0,1.0);

    // third vertex of M1
    M1_vertices[2].pos  = glm::vec3(1.0,1.0,-1.0);
    M1_vertices[2].norm = glm::vec3(0.0,0.0,1.0);

    // fourth vertex of M1
    M1_vertices[3].pos  = glm::vec3(-1.0,1.0,-1.0);
    M1_vertices[3].norm = glm::vec3(0.0,0.0,1.0);


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M1_indices.resize(3 * 2);

    // first triangle
    M1_indices[0] = 0;
    M1_indices[1] = 1;
    M1_indices[2] = 2;

    // second triangle
    M1_indices[3] = 2;
    M1_indices[4] = 3;
    M1_indices[5] = 0;
*/




    //// M2 : Cylinder
    // Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices
    M2_vertices.resize(4);

    // Vertices definitions
    M2_vertices[0].pos  = glm::vec3(0.0,-1.0,-1.1);
    M2_vertices[0].norm = glm::vec3(0.0,0.0,1.0);

    M2_vertices[1].pos  = glm::vec3(1.0,0.0,-1.1);
    M2_vertices[1].norm = glm::vec3(0.0,0.0,1.0);

    M2_vertices[2].pos  = glm::vec3(0.0,1.0,-1.1);
    M2_vertices[2].norm = glm::vec3(0.0,0.0,1.0);

    M2_vertices[3].pos  = glm::vec3(-1.0,0.0,-1.1);
    M2_vertices[3].norm = glm::vec3(0.0,0.0,1.0);


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M2_indices.resize(6);

    // indices definitions
    M2_indices[0] = 0;
    M2_indices[1] = 1;
    M2_indices[2] = 2;
    M2_indices[3] = 2;
    M2_indices[4] = 3;
    M2_indices[5] = 0;











    //// M3 : Sphere
    // Replace the code below, that creates a simple triangle, with the one to create a sphere.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices
    M3_vertices.resize(3);

    // Vertices definitions
    M3_vertices[0].pos  = glm::vec3(0.0,1.0,-1.2);
    M3_vertices[0].norm = glm::vec3(0.0,0.0,1.0);
    M3_vertices[1].pos  = glm::vec3(-0.866,-0.5,-1.2);
    M3_vertices[1].norm = glm::vec3(0.0,0.0,1.0);
    M3_vertices[2].pos  = glm::vec3(0.866,-0.5,-1.2);
    M3_vertices[2].norm = glm::vec3(0.0,0.0,1.0);


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M3_indices.resize(3);

    // indices definitions
    M3_indices[0] = 0;
    M3_indices[1] = 1;
    M3_indices[2] = 2;









    //// M4 : Spring
    // Replace the code below, that creates a simple octahedron, with the one to create a spring.
    M4_vertices.resize(6);

    // Vertices definitions
    M4_vertices[0].pos  = glm::vec3(0.0,1.414,-1.0);
    M4_vertices[0].norm = glm::vec3(0.0,0.0,1.0);
    M4_vertices[1].pos  = glm::vec3(0.0,-1.414,-1.0);
    M4_vertices[1].norm = glm::vec3(0.0,0.0,1.0);
    M4_vertices[2].pos  = glm::vec3(-1.0,0.0,-2.0);
    M4_vertices[2].norm = glm::vec3(0.0,0.0,1.0);
    M4_vertices[3].pos  = glm::vec3(-1.0,0.0,0.0);
    M4_vertices[3].norm = glm::vec3(0.0,-1.0,0.0);
    M4_vertices[4].pos  = glm::vec3(1.0,0.0,0.0);
    M4_vertices[4].norm = glm::vec3(0.0,-1.0,0.0);
    M4_vertices[5].pos  = glm::vec3(1.0,0.0,-2.0);
    M4_vertices[5].norm = glm::vec3(0.0,-1.0,0.0);


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M4_indices.resize(3 * 8);

    // indices definitions
    M4_indices[0]  = 0;
    M4_indices[1]  = 2;
    M4_indices[2]  = 3;
    M4_indices[3]  = 1;
    M4_indices[4]  = 3;
    M4_indices[5]  = 2;
    M4_indices[6]  = 0;
    M4_indices[7]  = 3;
    M4_indices[8]  = 4;
    M4_indices[9]  = 1;
    M4_indices[10] = 4;
    M4_indices[11] = 3;
    M4_indices[12] = 0;
    M4_indices[13] = 4;
    M4_indices[14] = 5;
    M4_indices[15] = 1;
    M4_indices[16] = 5;
    M4_indices[17] = 4;
    M4_indices[18] = 0;
    M4_indices[19] = 5;
    M4_indices[20] = 2;
    M4_indices[21] = 1;
    M4_indices[22] = 2;
    M4_indices[23] = 5;

}
