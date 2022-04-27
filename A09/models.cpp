// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {
    //// M1 : Cube
    // Replace the code below, that creates a simple square, with the one to create a cube.
    
    int sideLenght = 2.0;
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
    M1_indices[31] = 2;
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
    float height = 2;
    float cx = 0, cy = 0, cz = 0;
        
    
    M2_vertices.resize(3 * (NSlices * 2 + 2));

    // Upper circle
    M2_vertices[0]  = cx;
    M2_vertices[1]  = cy + height/2;
    M2_vertices[2]  = cz;
    
    for(int i=0;i<NSlices;i++){
        M2_vertices[(i+1)*3 + 0] = cx + radius * cos((float) i / NSlices * 2.0 * M_PI); //x for the vertex
        M2_vertices[(i+1)*3 + 1] = cy + height/2; //y for the vertex
        M2_vertices[(i+1)*3 + 2] = cz + radius * sin((float) i / NSlices * 2.0 * M_PI); // z for the vertex
    }
    
    //Lower circle
    M2_vertices[(NSlices+1)*3 + 0]  = cx;
    M2_vertices[(NSlices+1)*3 + 1]  = cy - height/2;
    M2_vertices[(NSlices+1)*3 + 2]  = cz;
    
    for(int i=NSlices+1;i<2*NSlices+1;i++){
        M2_vertices[(i+1)*3 + 0] = cx + radius * cos((float) (i-NSlices-1) / NSlices * 2.0 * M_PI); //x for the vertex
        M2_vertices[(i+1)*3 + 1] = cy - height/2; //y for the vertex
        M2_vertices[(i+1)*3 + 2] = cz + radius * sin((float) (i-NSlices-1) / NSlices * 2.0 * M_PI); // z for the vertex
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
        M2_indices[(2*NSlices + i)*3 + 0]= i+1;
        M2_indices[(2*NSlices + i)*3 + 1]= (i+1) % NSlices + 1;
        M2_indices[(2*NSlices + i)*3 + 2]= NSlices + i + 2;
    }
    
    for(int i=0;i<NSlices;i++){
        M2_indices[(3*NSlices + i)*3 + 0]= NSlices + i + 2;
        M2_indices[(3*NSlices + i)*3 + 1]= ((i+1) % NSlices) + NSlices + 2;
        M2_indices[(3*NSlices + i)*3 + 2]= (i+1) % NSlices + 1;
    }
    


    //// M3 : Sphere
    // Replace the code below, that creates a simple triangle, with the one to create a sphere.
    
    int sectorCount = 36;
    int stackCount = 9;
    
    M3_vertices.resize(3 * ((sectorCount+1) * (stackCount+1)));
    
    float sx = 0, sy = 0, sz = 0;
    float sRadius = 1.0;
    float teta, phi;
    
    M3_vertices[0] = sx;
    M3_vertices[1] = sy;
    M3_vertices[2] = sz;
    

    for(int i = 0; i <stackCount; i++){
        //teta = M_PI / 2 - i * (M_PI / stackCount);
        //teta = (float) (i-stackCount-1) / stackCount * M_PI;
        teta = (float) M_PI + (M_PI / stackCount)*(i+1);
        
        for(int j = 0; j < sectorCount; j++){
            //phi = j * (2 * M_PI / sectorCount);
            //phi = ((2 * M_PI) / (sectorCount-i)) * j;
            phi = (float) ((2 * M_PI) / sectorCount) * (j+1);
            //phi = (float) (j-sectorCount-1) / sectorCount * 2.0 * M_PI;
            
            M3_vertices[((i*3 + j)+1)*3 + 0] = sx + sRadius * sin(teta) * cos(phi);
            M3_vertices[((i*3 + j)+1)*3 + 1] = sy + sRadius * sin(teta);
            M3_vertices[((i*3 + j)+1)*3 + 2] = sz + sRadius * sin(teta) * sin(phi);
        }
    }

    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M3_indices.resize(3 * sectorCount * stackCount);
    
    /*
    for(int i = 0; i < stackCount; i++){
        for(int j = 0; j < sectorCount; j++){
            M3_indices[(i*3 + j)*3 + 0] = (i*sectorCount) + j;
            M3_indices[(i*3 + j)*3 + 1] = ((j+1) % sectorCount) + sectorCount*i;
            M3_indices[(i*3 + j)*3 + 2] = (i*sectorCount) + j + sectorCount;
        }
    }
     */
    
    for(int i = 0; i < stackCount; i++){
        for(int j = 0; j < sectorCount; j++){
            M3_indices[(i*3 + j)*3 + 0] = 0;
            M3_indices[(i*3 + j)*3 + 1] = ((j+1) % sectorCount) + sectorCount*i + 1;
            M3_indices[(i*3 + j)*3 + 2] = (i*sectorCount) + j + 1;
        }
    }





    //// M4 : Spring
    // Replace the code below, that creates a simple octahedron, with the one to create a spring.
    
    
    
    const int slices = 32;
    const int step = 5;
    float rounds = 4, thickness = 1;
    
    M4_vertices.resize(3 * ((rounds * 360 + step)*slices));
    
    for (int i = -slices; i <= rounds * 360 + step; i += step)
    {
        for (int j = 0; j < slices; j ++)
        {
            GLfloat t = (GLfloat)i / 360 + (GLfloat)j / slices * step / 360;
            t = std::max(0.0f, std::min(rounds, t));
            GLfloat a1 = t * M_PI * 2;
            GLfloat a2 = (GLfloat)j / slices * M_PI * 2;
            GLfloat d = radius + thickness * cos(a2);
            M4_vertices.push_back(d * cos(a1));
            M4_vertices.push_back(d * sin(a1));
            M4_vertices.push_back(thickness * sin(a2) + height * t / rounds);
        }
    }
    
    M4_indices.resize(2 * (M4_vertices.size() / 3 - slices));
    
    for (int i = 0; i < M4_vertices.size() / 3 - slices; ++i)
    {
        M4_indices.push_back(i);
        M4_indices.push_back(i + slices);
    }
}

