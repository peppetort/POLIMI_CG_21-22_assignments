// Rotate 45 degrees around an arbitrary axis passing through (1,0,-1). The x-axis can be aligned to the arbitrary axis after a rotation of 30 degrees around the z-axis, and then -60 degrees around the y-axis.
glm::mat4 MT1 = glm::mat4(1);

glm::mat4 translation_1 = glm::translate(glm::mat4(1), glm::vec3(1,0,-1));
glm::mat4 rotation1_1 = glm::rotate(glm::mat4(1), glm::radians(30.f), glm::vec3(0,0,1));
glm::mat4 rotation2_1 = glm::rotate(glm::mat4(1), glm::radians(-60.f), glm::vec3(0,1,0));
glm::mat4 real_rotation_1 = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3(1,0,0));

MT1 = translation_1 * rotation2_1 * rotation1_1 * real_rotation_1 * glm::inverse(rotation1_1) * glm::inverse(rotation2_1) * glm::inverse(translation_1);


           
// Half the size of an object, using as fixed point (5,0,-2)
glm::mat4 MT2 = glm::mat4(1);

glm::mat4 scaling_2 = glm::scale(glm::mat4(1), glm::vec3(0.5));
glm::mat4 translation_2 = glm::translate(glm::mat4(1), glm::vec3(5,0,-2));

MT2 = translation_2 * scaling_2 * glm::inverse(translation_2);
           
// Mirror the starship along a plane passing through (1,1,1), and obtained rotating 15 degree around the x axis the xz plane
glm::mat4 MT3 = glm::mat4(1);

glm::mat4 rotation_3 = glm::rotate(glm::mat4(1), glm::radians(15.f), glm::vec3(1,0,0));
glm::mat4 scaling_3 = glm::scale(glm::mat4(1), glm::vec3(1,-1,1));
glm::mat4 translation_3 = glm::translate(glm::mat4(1), glm::vec3(1,1,1));

MT3 =  translation_3 * rotation_3 * scaling_3 * glm::inverse(rotation_3) * glm::inverse(translation_3);





// Apply the inverse of the following sequence of transforms: Translation of (0, 0, 5) then rotation of 30 degree around the Y axis, and finally a uniform scaling of a factor of 3.
glm::mat4 MT4 = glm::mat4(1);

glm::mat4 translation_4 = glm::translate(glm::mat4(1), glm::vec3(0,0,5));
glm::mat4 rotation_4 = glm::rotate(glm::mat4(1), glm::radians(30.f), glm::vec3(0,1,0));
glm::mat4 scaling_4 = glm::scale(glm::mat4(1), glm::vec3(3));

MT4 = glm::inverse(scaling_4 * rotation_4 * translation_4);

