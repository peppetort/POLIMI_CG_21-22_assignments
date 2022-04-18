float w = 2;
float n = -4;
float f = 12;

// Create a matrix for Isometric projection with the given aspect ration a
glm::mat4 PO1(float a) {
    glm::mat4 rot_45 = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3(0,1,0));
    glm::mat4 rot_35 = glm::rotate(glm::mat4(1), glm::radians(35.26f), glm::vec3(1,0,0));
    
    glm::mat4 port = glm::scale(glm::mat4(1.0), glm::vec3(1,-1,1)) * glm::ortho(-w, w, -w/a, w/a, n, f);
    
    glm::mat4 out = port * rot_35 * rot_45;
	return out;
    
}

// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
glm::mat4 PO2(float a) {
    glm::mat4 rot_45_y = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3(0,1,0));
    glm::mat4 rot_45_x = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3(1,0,0));
    
    glm::mat4 port = glm::scale(glm::mat4(1.0), glm::vec3(1,-1,1)) * glm::ortho(-w, w, -w/a, w/a, n, f);
    glm::mat4 out = port * rot_45_x * rot_45_y;
	return out;
}

// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
glm::mat4 PO3(float a) {
    glm::mat4 rot_60_y = glm::rotate(glm::mat4(1), glm::radians(60.f), glm::vec3(0,1,0));
    glm::mat4 rot_45_x = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3(1,0,0));
    
    glm::mat4 port = glm::scale(glm::mat4(1.0), glm::vec3(1,-1,1)) * glm::ortho(-w, w, -w/a, w/a, n, f);
    
	glm::mat4 out = port * rot_45_x * rot_60_y;
	return out;
}

// Create a matrix for Cabinet projection (alpha = 45)
// with the given aspect ration a
glm::mat4 PO4(float a) {
    glm::mat4 shear_45 = glm::mat4(1,0,0,0,
                                   0,1,0,0,
                                   -0.5*cos(glm::radians(45.f)),-0.5*sin(glm::radians(45.f)),1,0,
                                   0,0,0,1);
    
    glm::mat4 port = glm::scale(glm::mat4(1.0), glm::vec3(1,-1,1)) * glm::ortho(-w, w, -w/a, w/a, n, f);
    glm::mat4 out = port * shear_45;
	return out;
}

