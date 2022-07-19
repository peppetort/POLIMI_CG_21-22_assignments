 // Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)
glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {

    glm::mat4 roll = glm::rotate(glm::mat4(1), Angs.z, glm::vec3(0,0,1));
    glm::mat4 elevation = glm::rotate(glm::mat4(1), Angs.y, glm::vec3(1,0,0));
    glm::mat4 direction = glm::rotate(glm::mat4(1), Angs.x, glm::vec3(0,1,0));
    glm::mat4 translation = glm::translate(glm::mat4(1), Pos);
    
    glm::mat4 camera = translation * direction * elevation * roll;
    //glm::mat4 camera = translation * roll * elevation * direction;
    glm::mat4 view = glm::inverse(camera);

	return view;

}

 // Create a look at matrix
 // Pos    -> Position of the camera (c)
 // aim    -> Posizion of the target (a)
 // Roll   -> roll (rho)
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
    glm::mat4 roll = glm::rotate(glm::mat4(1), glm::radians(Roll), glm::vec3(0,0,1));
    glm::mat4 view = glm::lookAt(Pos, aim, glm::vec3(0,1,0));
    
    glm::mat4 out = roll * view;
	return out;
}



