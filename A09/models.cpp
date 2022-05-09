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
    float xCircle, yCircle, zCircle, xyCircle;
    float radiusCircle = 2.0f;
    float stackCount = 48.0f; //24.0f;
    float sectorCount = 144.0f; //72.0f;
    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;
    int valueOfArrayCircle = 0;
    int valueOfSecondArrayCircle = 0;
    int k1Circle, k2Circle;
    
    M3_vertices.resize(3 * stackCount * sectorCount * 2);
    
    
    for(int i=0;i<=stackCount;i++){
        stackAngle = M_PI / 2 - i * stackStep;
        xyCircle = radiusCircle * cos(stackAngle);
        zCircle = radiusCircle * sin(stackAngle);
        
        for(int j=0;j<=sectorCount;j++){
            sectorAngle = j * sectorStep;
            
            xCircle = xyCircle * cos(sectorAngle);
            yCircle = xyCircle * sin(sectorAngle);
            M3_vertices[(valueOfArrayCircle * 3) + 0] = xCircle;
            M3_vertices[(valueOfArrayCircle * 3) + 1] = yCircle;
            M3_vertices[(valueOfArrayCircle * 3) + 2] = zCircle;
            valueOfArrayCircle++;
        }
    }
    
    M3_indices.resize(3 * stackCount * sectorCount * 2);
    
    for(int i=0;i<stackCount;i++){
        k1Circle = i * (sectorCount + 1);
        k2Circle = k1Circle + sectorCount + 1;
        
        for(int j=0;j<sectorCount;j++, k1Circle++, k2Circle++){
            if(i != 0){
                M3_indices[valueOfSecondArrayCircle] = k1Circle;
                valueOfSecondArrayCircle++;
                M3_indices[valueOfSecondArrayCircle] = k2Circle;
                valueOfSecondArrayCircle++;
                M3_indices[valueOfSecondArrayCircle] = k1Circle + 1;
                valueOfSecondArrayCircle++;
            }
            
            if(i != stackCount -1){
                M3_indices[valueOfSecondArrayCircle] = k1Circle + 1;
                valueOfSecondArrayCircle++;
                M3_indices[valueOfSecondArrayCircle] = k2Circle;
                valueOfSecondArrayCircle++;
                M3_indices[valueOfSecondArrayCircle] = k2Circle + 1;
                valueOfSecondArrayCircle++;
            }
        }
    }

    //// M4 : Spring
    // Replace the code below, that creates a simple octahedron, with the one to create a spring.
    
    
    int nSSlices = 36;
    float steps = 100;
    float r = 1; //cylinder radius
    float R = 2; //distance from the center of cylinder from center of the spring
    float P = 1; //speed of movment
    float n = 4; //number of rounds
    float t = 0.f;
    
    float sCx = 0, sCy = 0, sCz = 0;
    
        
    
    M4_vertices.resize(3 * (steps * nSSlices));
    
    
    for(int i=0;i<steps;i++){
        t = (float) i / steps * 2.0 * M_PI;
        sCx = R * cos(t);
        sCy = 2 * t;
        sCy = R * sin(t);
        for(int j=0;j<nSSlices;i++){
            M4_vertices[j*3 + i + 0] = sCx + r * cos((float) j / nSSlices * 2.0 * M_PI); //x for the vertex
            M4_vertices[j*3 + i + 1] = sCy; //y for the vertex
            M4_vertices[j*3 + i + 2] = sCz + r * sin((float) j / nSSlices * 2.0 * M_PI); // z for the vertex
        }
    }
    
    M4_indices.resize(3 * (steps*nSSlices));
    
    for(int i=0;i<steps;i++){
        for(int j=0;i<nSSlices;j++){
            M4_indices[i*j*3+0]= i*j;
            M4_indices[i*j*3+1]= i*j + nSSlices;
            M4_indices[i*j*3+2]= ((i*j+1) % nSSlices) + nSSlices*i*j + 2;
        }
    }

}

