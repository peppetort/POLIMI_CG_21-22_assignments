

// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	static glm::vec3 pos = glm::vec3(-3,0,2);	// variable to store robot position
												// here glm::vec3(-3,0,2) represents a
												// meaningful initial position for the robot
												//
												// this variable is here just as an example!
												// it should replaced or combined with
												//  the ones you think necessary for the task
    static float lookYaw = 0.0;
    static float lookPitch = 0.0;
    static float lookRoll = 0.0;
    
    static auto startTime = std::chrono::high_resolution_clock::now();
    static float lastTime = 0.0f;
    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>
            (currentTime - startTime).count();
    float deltaT = time - lastTime;
    lastTime = time;
    
    const float MOVE_SPEED = 2.f;
    const float ROTATION_SPEED = glm::radians(60.f);
    
    if(glfwGetKey(window, GLFW_KEY_A)){
        pos -= MOVE_SPEED * glm::vec3(glm::rotate(glm::mat4(1.0f), lookYaw,
                                glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(1,0,0,1)) * deltaT;
    }
    if(glfwGetKey(window, GLFW_KEY_D)){
        pos += MOVE_SPEED * glm::vec3(glm::rotate(glm::mat4(1.0f), lookYaw,
                                    glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(1,0,0,1)) * deltaT;
    }
    if(glfwGetKey(window, GLFW_KEY_W)){
        pos -= MOVE_SPEED * glm::vec3(glm::rotate(glm::mat4(1.0f), lookYaw,
                                glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(0,0,1,1)) * deltaT;
    }
    if(glfwGetKey(window, GLFW_KEY_S)){
        pos += MOVE_SPEED * glm::vec3(glm::rotate(glm::mat4(1.0f), lookYaw,
                                glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(0,0,1,1)) * deltaT;
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT)){
        lookYaw -= deltaT * ROTATION_SPEED;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT)){
        lookYaw += deltaT * ROTATION_SPEED;
    }
    
    glm::mat4 translation = glm::translate(glm::mat4(1), pos);
    glm::mat4 rotation = glm::mat4(glm::quat(glm::vec3(0, lookYaw + 90.f, 0)) * // align direction with position update
                                   glm::quat(glm::vec3(lookPitch, 0, 0)) *
                                   glm::quat(glm::vec3(0, 0, lookRoll)));
    
    glm::mat4 worldMatrix = translation * rotation;
	return worldMatrix;
}


