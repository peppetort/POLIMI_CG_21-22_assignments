

// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	static glm::vec3 pos = glm::vec3(-3,0,2);	// variable to store robot position
												// here glm::vec3(-3,0,2) represents a
												// meaningful initial position for the robot
												//
												// this variable is here just as an example!
												// it should replaced or combined with
												//  the ones you think necessary for the task
    static glm::quat dir = glm::quat(1,0,0,0);
    const float MOVE_SPEED = 0.02;

    
    static auto startTime = std::chrono::high_resolution_clock::now();
    static float lastTime = 0.0f;
    auto currentTime = std::chrono::high_resolution_clock::now();
    static float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
    float deltaT = time - lastTime;
    lastTime = time;
    
    if(glfwGetKey(window, GLFW_KEY_A)){
        pos -= MOVE_SPEED * glm::vec3(1,0,0);
        dir = glm::quat(glm::vec3(0, glm::radians(180.f), 0));
    }
    if(glfwGetKey(window, GLFW_KEY_D)){
        pos += MOVE_SPEED * glm::vec3(1,0,0);
        dir = glm::quat(glm::vec3(0, glm::radians(0.f), 0));
    }
    if(glfwGetKey(window, GLFW_KEY_W)){
        pos -= MOVE_SPEED * glm::vec3(0,0,1);
        dir = glm::quat(glm::vec3(0, glm::radians(90.f), 0));
    }
    if(glfwGetKey(window, GLFW_KEY_S)){
        pos += MOVE_SPEED * glm::vec3(0,0,1);
        dir = glm::quat(glm::vec3(0, glm::radians(-90.f), 0));
    }
    
    glm::mat4 translation = glm::translate(glm::mat4(1), pos);
    glm::mat4 rotation = glm::mat4(dir);
    
    glm::mat4 worldMatrix = translation * rotation;
	return worldMatrix;
}


