// Create a world matrix using position, Euler angles, and size
// Euler angles are passed in YPR parameter:
// YPR.x : Yaw
// YPR.y : Pitch
// YPR.z : Roll
glm::mat4 MakeWorldMatrixEuler(glm::vec3 pos, glm::vec3 YPR, glm::vec3 size) {
    glm::mat4 translation = glm::translate(glm::mat4(1), pos);
    glm::mat4 scaling = glm::scale(glm::mat4(1), size);
    // in z-up convention
    //  yaw: rotation along z-ax
    //  pith: rotation along y-ax
    //  roll: rotation along x-az
    // in y-up convention
    //  yaw: rotation along y-ax
    //  roll: rotation along z-ax
    //  pitch: rotation along x-ax
    glm::mat4 yaw = glm::rotate(glm::mat4(1), glm::radians(YPR.x), glm::vec3(0,1,0));
    glm::mat4 pich = glm::rotate(glm::mat4(1), glm::radians(YPR.y), glm::vec3(1,0,0));
    glm::mat4 roll = glm::rotate(glm::mat4(1), glm::radians(YPR.z), glm::vec3(0,0,1));
    
    glm::mat4 out = translation * yaw * pich * roll * scaling;
	return out;
}

// Create a world matrix using position, quaternion angles, and size
glm::mat4 MakeWorldMatrixQuat(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
    glm::mat4 translation = glm::translate(glm::mat4(1), pos);
    glm::mat4 scaling = glm::scale(glm::mat4(1), size);
    glm::mat4 quat_rotation = glm::mat4(rQ);
    
    glm::mat4 out = translation * quat_rotation * scaling;
	return out;
}

