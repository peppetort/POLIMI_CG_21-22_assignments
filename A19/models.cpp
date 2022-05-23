// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {
    //// M1 : Cube
    M1_vertices.resize(8*3);

    // first vertex of M1
    M1_vertices[0].pos  = glm::vec3(-1.0,-1.0,-1.0);
    M1_vertices[0].norm = glm::vec3(0.0,0.0,-1.0);
    M1_vertices[0].UV   = glm::vec2(0.125,0.375);

    // second vertex of M1
    M1_vertices[1].pos  = glm::vec3(1.0,-1.0,-1.0);
    M1_vertices[1].norm = glm::vec3(0.0,0.0,-1.0);
    M1_vertices[1].UV   = glm::vec2(0.25,0.375);

    // third vertex of M1
    M1_vertices[2].pos  = glm::vec3(1.0,1.0,-1.0);
    M1_vertices[2].norm = glm::vec3(0.0,0.0,-1.0);
    M1_vertices[2].UV   = glm::vec2(0.25,0.25);

    // fourth vertex of M1
    M1_vertices[3].pos  = glm::vec3(-1.0,1.0,-1.0);
    M1_vertices[3].norm = glm::vec3(0.0,0.0,-1.0);
    M1_vertices[3].UV   = glm::vec2(0.125,0.25);
    
    //---------------------------------
    M1_vertices[4].pos  = glm::vec3(1.0,-1.0,-1.0);
    M1_vertices[4].norm = glm::vec3(1.0,0.0,0.0);
    M1_vertices[4].UV   = glm::vec2(0.25,0.375);

    M1_vertices[5].pos  = glm::vec3(1.0,-1.0,1.0);
    M1_vertices[5].norm = glm::vec3(1.0,0.0,0.0);
    M1_vertices[5].UV   = glm::vec2(0.375,0.375);

    M1_vertices[6].pos  = glm::vec3(1.0,1.0,1.0);
    M1_vertices[6].norm = glm::vec3(1.0,0.0,0.0);
    M1_vertices[6].UV   = glm::vec2(0.375,0.25);

    M1_vertices[7].pos  = glm::vec3(1.0,1.0,-1.0);
    M1_vertices[7].norm = glm::vec3(1.0,0.0,0.0);
    M1_vertices[7].UV   = glm::vec2(0.25,0.25);

    //---------------------------------
    M1_vertices[8].pos  = glm::vec3(1.0,-1.0,1.0);
    M1_vertices[8].norm = glm::vec3(0.0,0.0,1.0);
    M1_vertices[8].UV   = glm::vec2(0.25,0.0);

    M1_vertices[9].pos  = glm::vec3(-1.0,-1.0,1.0);
    M1_vertices[9].norm = glm::vec3(0.0,0.0,1.0);
    M1_vertices[9].UV   = glm::vec2(0.125,0.0);

    M1_vertices[10].pos  = glm::vec3(-1.0,1.0,1.0);
    M1_vertices[10].norm = glm::vec3(0.0,0.0,1.0);
    M1_vertices[10].UV   = glm::vec2(0.125,0.125);

    M1_vertices[11].pos  = glm::vec3(1.0,1.0,1.0);
    M1_vertices[11].norm = glm::vec3(0.0,0.0,1.0);
    M1_vertices[11].UV   = glm::vec2(0.25,0.125);
    
    //---------------------------------
    M1_vertices[12].pos  = glm::vec3(-1.0,-1.0,1.0);
    M1_vertices[12].norm = glm::vec3(-1.0,0.0,0.0);
    M1_vertices[12].UV   = glm::vec2(0.0,0.375);

    M1_vertices[13].pos  = glm::vec3(-1.0,-1.0,-1.0);
    M1_vertices[13].norm = glm::vec3(-1.0,0.0,0.0);
    M1_vertices[13].UV   = glm::vec2(0.125,0.375);

    M1_vertices[14].pos  = glm::vec3(-1.0,1.0,-1.0);
    M1_vertices[14].norm = glm::vec3(-1.0,0.0,0.0);
    M1_vertices[14].UV   = glm::vec2(0.125,0.25);

    M1_vertices[15].pos  = glm::vec3(-1.0,1.0,1.0);
    M1_vertices[15].norm = glm::vec3(-1.0,0.0,0.0);
    M1_vertices[15].UV   = glm::vec2(0.0,0.25);
    
    //---------------------------------
    M1_vertices[16].pos  = glm::vec3(-1.0,1.0,1.0);
    M1_vertices[16].norm = glm::vec3(0.0,1.0,0.0);
    M1_vertices[16].UV   = glm::vec2(0.125,0.125);

    M1_vertices[17].pos  = glm::vec3(1.0,1.0,1.0);
    M1_vertices[17].norm = glm::vec3(0.0,1.0,0.0);
    M1_vertices[17].UV   = glm::vec2(0.25,0.125);

    M1_vertices[18].pos  = glm::vec3(1.0,1.0,-1.0);
    M1_vertices[18].norm = glm::vec3(0.0,1.0,0.0);
    M1_vertices[18].UV   = glm::vec2(0.25,0.25);

    M1_vertices[19].pos  = glm::vec3(-1.0,1.0,-1.0);
    M1_vertices[19].norm = glm::vec3(0.0,1.0,0.0);
    M1_vertices[19].UV   = glm::vec2(0.125,0.25);
    
    //---------------------------------
    M1_vertices[20].pos  = glm::vec3(-1.0,-1.0,1.0);
    M1_vertices[20].norm = glm::vec3(0.0,-1.0,0.0);
    M1_vertices[20].UV   = glm::vec2(0.125,0.5);

    M1_vertices[21].pos  = glm::vec3(1.0,-1.0,1.0);
    M1_vertices[21].norm = glm::vec3(0.0,-1.0,0.0);
    M1_vertices[21].UV   = glm::vec2(0.25,0.5);

    M1_vertices[22].pos  = glm::vec3(1.0,-1.0,-1.0);
    M1_vertices[22].norm = glm::vec3(0.0,-1.0,0.0);
    M1_vertices[22].UV   = glm::vec2(0.25,0.375);

    M1_vertices[23].pos  = glm::vec3(-1.0,-1.0,-1.0);
    M1_vertices[23].norm = glm::vec3(0.0,-1.0,0.0);
    M1_vertices[23].UV   = glm::vec2(0.125,0.375);


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
    
    // -------------------
    M1_indices[6] = 4;
    M1_indices[7] = 5;
    M1_indices[8] = 6;

    M1_indices[9] = 6;
    M1_indices[10] = 7;
    M1_indices[11] = 4;
    
    // -------------------
    M1_indices[12] = 8;
    M1_indices[13] = 9;
    M1_indices[14] = 11;

    M1_indices[15] = 11;
    M1_indices[16] = 10;
    M1_indices[17] = 9;
    
    // -------------------
    M1_indices[18] = 12;
    M1_indices[19] = 13;
    M1_indices[20] = 14;

    M1_indices[21] = 14;
    M1_indices[22] = 15;
    M1_indices[23] = 12;
    
    // -------------------
    M1_indices[24] = 16;
    M1_indices[25] = 17;
    M1_indices[26] = 18;

    M1_indices[27] = 18;
    M1_indices[28] = 19;
    M1_indices[29] = 16;
    
    // -------------------
    M1_indices[30] = 20;
    M1_indices[31] = 21;
    M1_indices[32] = 22;

    M1_indices[33] = 22;
    M1_indices[34] = 23;
    M1_indices[35] = 20;
    
    


    //// M2 : Cylinder
    // Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices
    int NSlices = 36;
    float radius = 1;
    float height = 3;
    float cx = 0, cy = 0, cz = 0;
    
    int baseIndex = 0;
        
    
    M2_vertices.resize(NSlices * 4 + 2);

    // Upper circle
    M2_vertices[baseIndex].pos = glm::vec3(cx, cy + height/2, cz);
    M2_vertices[baseIndex].norm = glm::vec3(0, 1, 0);
    M2_vertices[baseIndex].UV = glm::vec2(0.625, 0.125);
    
    baseIndex = 1;
    
    
    for(int i=0;i<NSlices;i++){
        float x = cx + radius * cos((float) i / NSlices * 2.0 * M_PI);
        float y = cy + height/2;
        float z = cz + radius * sin((float) i / NSlices * 2.0 * M_PI);
        
        float u = 0.625 + 0.125 * cos((float) i / NSlices * 2.0 * M_PI);
        float v = 0.125 + 0.125 * sin((float) i / NSlices * 2.0 * M_PI);
        
        M2_vertices[baseIndex + i].pos = glm::vec3(x, y, z);
        M2_vertices[baseIndex + i].norm = glm::vec3(0, 1, 0);
        M2_vertices[baseIndex + i].UV = glm::vec2(u, v);
    }
    
    baseIndex = NSlices + 1;
    
    //Lower circle
    M2_vertices[baseIndex].pos = glm::vec3(cx, cy - height/2, cz);
    M2_vertices[baseIndex].norm = glm::vec3(0, -1, 0);
    M2_vertices[baseIndex].UV = glm::vec2(0.875, 0.125);
      
    baseIndex = NSlices + 2;
    
    for(int i=0;i<NSlices;i++){
        float x = cx + radius * cos((float) i / NSlices * 2.0 * M_PI);
        float y = cy - height/2;
        float z = cz + radius * sin((float) i / NSlices * 2.0 * M_PI);
        
        float u = 0.875 + 0.125 * cos((float) i / NSlices * 2.0 * M_PI);
        float v = 0.125 + 0.125 * sin((float) i / NSlices * 2.0 * M_PI);
        
        M2_vertices[baseIndex + i].pos = glm::vec3(x, y, z);
        M2_vertices[baseIndex + i].norm = glm::vec3(0, -1, 0);
        M2_vertices[baseIndex + i].UV = glm::vec2(u, v);
    }
    
    baseIndex = 2*NSlices + 2;
    
    float step = 0.5 / NSlices;
    float u = 1;
    float v = 0.25;
    for(int i=0;i<NSlices;i++){
        float x = cx + radius * cos((float) i / NSlices * 2.0 * M_PI);
        float y = cy + height/2;
        float z = cz + radius * sin((float) i / NSlices * 2.0 * M_PI);
        
        if(i != 0 ){
            u = u - step;
        }
    
        
        float nx = cos((float) i / NSlices * 2.0 * M_PI);
        float nz = sin((float) i / NSlices * 2.0 * M_PI);
        
        M2_vertices[baseIndex + i].pos = glm::vec3(x, y, z);
        M2_vertices[baseIndex + i].norm = glm::vec3(nx, 0, nz);
        M2_vertices[baseIndex + i].UV = glm::vec2(u, v);
    }
    
    baseIndex = 3*NSlices + 2;
    
    u = 1;
    v = 0.5;
    for(int i=0;i<NSlices;i++){
        float x = cx + radius * cos((float) i / NSlices * 2.0 * M_PI);
        float y = cy - height/2;
        float z = cz + radius * sin((float) i / NSlices * 2.0 * M_PI);
        
        if(i != 0 ){
            u = u - step;
        }
    
        
        float nx = cos((float) i / NSlices * 2.0 * M_PI);
        float nz = sin((float) i / NSlices * 2.0 * M_PI);
        
        M2_vertices[baseIndex + i].pos = glm::vec3(x, y, z);
        M2_vertices[baseIndex + i].norm = glm::vec3(nx, 0, nz);
        M2_vertices[baseIndex + i].UV = glm::vec2(u, v);
    }
    

    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M2_indices.resize(3 * (NSlices * 4));
    
    
   for(int i=0;i<NSlices;i++){
        M2_indices[i*3+0]= 0;
        M2_indices[i*3+1]= i+1;
        M2_indices[i*3+2]= (i+1) % NSlices + 1;
    }
    

    for(int i=NSlices;i<2*NSlices;i++){
        M2_indices[i*3+0]= NSlices + 1;
        M2_indices[i*3+1]= i+2;
        M2_indices[i*3+2]= ((i+1) % NSlices) + NSlices + 2;
    }
    
    for(int i=0;i<NSlices;i++){
        M2_indices[(2*NSlices + i)*3 + 0]= 2*NSlices+2 + i;
        M2_indices[(2*NSlices + i)*3 + 1]= ((i+1) % NSlices) + 2*NSlices+2;
        M2_indices[(2*NSlices + i)*3 + 2]= 3*NSlices+2 + i;
    }
    
    
    for(int i=0;i<NSlices;i++){
        M2_indices[(3*NSlices + i)*3 + 0]= 3*NSlices+2 + i;
        M2_indices[(3*NSlices + i)*3 + 1]= ((i+1) % NSlices) + 3*NSlices+2;
        M2_indices[(3*NSlices + i)*3 + 2]= ((i+1) % NSlices) + 2*NSlices+2;
    }
    
}
