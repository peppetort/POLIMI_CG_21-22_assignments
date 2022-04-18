// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {
    //// M1 : Cube
    // Replace the code below, that creates a simple square, with the one to create a cube.
    
    int sideLenght = 3.0;
    float ox = -1.0, oy = -1.0, oz = -1.0;
    float lastx= ox,  lasty= oy,  lastz= oz;

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices components (3 * number of vertices)
    M1_vertices.resize(3 * 8);
    
    M1_vertices[0] = lastx;
    M1_vertices[1] = lasty;
    M1_vertices[2] = lastz;
    
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
        
        M1_vertices[(i+1)*3 + 0] = lastx;
        M1_vertices[(i+1)*3 + 1] = lasty;
        M1_vertices[(i+1)*3 + 2] = lastz;
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
    M1_indices[31] = 4;
    M1_indices[32] = 6;

    M1_indices[33] = 6;
    M1_indices[34] = 3;
    M1_indices[35] = 7;






    //// M2 : Cylinder
    // Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices components (3 * number of vertices)
    int NSlices = 36;
    float radius = 1;
    float height = 4;
    float cx = 0, cy = 0, cz = 0;
        
    
    M2_vertices.resize(3 * (NSlices * 2 + 2));

    // Upper circle
    M2_vertices[0]  = cx;
    M2_vertices[1]  = cy + height/2;
    M2_vertices[2]  = cz;
    
    int i;
    int lastIndex;
    for(i=0;i<NSlices;i++){
        M2_vertices[(i+1)*3 + 0] = cx + radius * cos((float) i / NSlices * 2.0 * M_PI); //x for the vertex
        M2_vertices[(i+1)*3 + 1] = cy + height/2; //y for the vertex
        M2_vertices[(i+1)*3 + 2] = cz + radius * sin((float) i / NSlices * 2.0 * M_PI); // z for the vertex
    }
    
    lastIndex = i+1;
    
    //Lower circle
    M2_vertices[lastIndex*3 + 0]  = cx;
    M2_vertices[lastIndex*3 + 1]  = cy - height/2;
    M2_vertices[lastIndex*3 + 2]  = cz;
    
    for(int i=0;i<NSlices;i++){
        M2_vertices[(lastIndex + i+1)*3 + 0] = cx + radius * cos((float) i / NSlices * 2.0 * M_PI); //x for the vertex
        M2_vertices[(lastIndex + i+1)*3 + 1] = cy - height/2; //y for the vertex
        M2_vertices[(lastIndex + i+1)*3 + 2] = cz + radius * sin((float) i / NSlices * 2.0 * M_PI); // z for the vertex
    }

    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M2_indices.resize(3 * NSlices * 4);
    
    
   for(int i=0;i<NSlices;i++){
        M2_indices[i*3+0]= 0;
        M2_indices[i*3+1]= i+1;
        M2_indices[i*3+2]= (i+1) % NSlices + 1;
    }
    
    
    lastIndex = NSlices;
    int secondCyrcleCenterIndex = NSlices + 1;
    
    for(int j=0;j<NSlices; j++){
        M2_indices[(lastIndex + j)*3+0]= secondCyrcleCenterIndex;
        M2_indices[(lastIndex + j)*3+1]= secondCyrcleCenterIndex + j + 1;
        M2_indices[(lastIndex + j)*3+2]= ((j + 1) % NSlices + 1) + secondCyrcleCenterIndex;
    }
    lastIndex = lastIndex + NSlices;
    
    for(int i=0;i<NSlices; i++){
        M2_indices[(lastIndex + i)*3+0]= (i+1);
        M2_indices[(lastIndex + i)*3+1]= (i+1) % NSlices + 1;
        M2_indices[(lastIndex + i)*3+2]= secondCyrcleCenterIndex + i+1;
    }
    lastIndex = lastIndex + NSlices;
    
    for(int i=0;i<NSlices; i++){
        M2_indices[(lastIndex + i)*3+0]= (secondCyrcleCenterIndex+i+1);
        M2_indices[(lastIndex + i)*3+1]= ((i+1) % NSlices + 1) + secondCyrcleCenterIndex;
        M2_indices[(lastIndex + i)*3+2]= (i+1) % NSlices + 1;
    }
    
  /*  for (int i = (3 * NSlices * 2) - 1; i >= 0; i--)
        std::cout << M2_indices[i];*/
    



    //// M3 : Sphere
    // Replace the code below, that creates a simple triangle, with the one to create a sphere.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices components (3 * number of vertices)
    float sRadius = 1;
    float sSLices = 4;
    float sx = 0.0, sy = 0.0, sz = 0.0;
    
    
    M3_vertices.resize(3 * (sSLices*sSLices*2 + 2));
    
    float teta;
    float phi;
    for(int j=0;j<sSLices;j++){
        teta = (float) j / sSLices * 2.0 * M_PI;
        for(int i=0;i<sSLices;i++){
            phi = (float) i / sSLices * 2.0 * M_PI;
            M2_vertices[(j+i+1)*3 + 0] = sx + sRadius * sin(teta) * cos(phi); //x for the vertex
            M2_vertices[(j+i+1)*3 + 1] = sy + sRadius * cos(teta); //y for the vertex
            M2_vertices[(j+i+1)*3 + 2] = sz + sRadius * sin(teta) * sin(phi); // z for the vertex
        }
    }


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M3_indices.resize(3);

    // indices definitions
    M3_indices[0] = 0;
    M3_indices[1] = 1;
    M3_indices[2] = 2;









    //// M4 : Spring
    // Replace the code below, that creates a simple octahedron, with the one to create a spring.
    M4_vertices.resize(3 * 6);

    // Vertices definitions
    M4_vertices[0]  =  0.0;
    M4_vertices[1]  =  1.414;
    M4_vertices[2]  = -1.0;
    M4_vertices[3]  =  0.0;
    M4_vertices[4]  = -1.414;
    M4_vertices[5]  = -1.0;
    M4_vertices[6]  = -1.0;
    M4_vertices[7]  =  0.0;
    M4_vertices[8]  = -2.0;
    M4_vertices[9]  = -1.0;
    M4_vertices[10] =  0.0;
    M4_vertices[11] =  0.0;
    M4_vertices[12] =  1.0;
    M4_vertices[13] =  0.0;
    M4_vertices[14] =  0.0;
    M4_vertices[15] =  1.0;
    M4_vertices[16] =  0.0;
    M4_vertices[17] = -2.0;


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

