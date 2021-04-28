#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <config.h>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#define LOG(msg) \
    std::cout << msg << std::endl

#define LOG_MATRIX(mat) \
    std::cout << glm::to_string(mat) << std::endl;

int main(int argc, char *argv[])
{
    // Question 1
    float fm0[9] = {
        0.5f,
        0.0f,
        0.0f,
        0.0f,
        2.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f};

    glm::mat3x3 m0 = glm::make_mat3(fm0);

    LOG("m0 =");
    LOG_MATRIX(m0);

    //--

    float fm1[16] = {
        1.0f,
        0.0f,
        1.0f,
        0.0f,
        1.0f,
        -2.0f,
        0.0f,
        0.0f,
        1.0f};

    glm::mat3x3 m1 = glm::make_mat3(fm1);

    LOG("m1 =");
    LOG_MATRIX(m1);

    //--

    glm::mat3x3 result = m1 * m0;

    LOG("m1 * m0 =");
    LOG_MATRIX(result);

    //--

    glm::mat3x3 composite_matrix = m0 * m1;

    LOG("m0 * m1 =");
    LOG_MATRIX(composite_matrix);

    //--

    glm::vec3 house1(0.0, 0.0, 0.0);

    glm::vec3 transform1 = house1 * composite_matrix;

    LOG("Transform 1 = ");
    LOG_MATRIX(transform1);

    //--

    glm::vec3 house2(0.0, 2.0, 0.0);

    glm::vec3 transform2 = house2 * composite_matrix;

    LOG("Transform 2 = ");
    LOG_MATRIX(transform2);

    //--

    glm::vec3 house3(1.0, 3.0, 0.0);

    glm::vec3 transform3 = house3 * composite_matrix;

    LOG("Transform 3 = ");
    LOG_MATRIX(transform3);

    //--

    glm::vec3 house4(2.0, 2.0, 0.0);

    glm::vec3 transform4 = house4 * composite_matrix;

    LOG("Transform 4 = ");
    LOG_MATRIX(transform4);

    //--

    LOG("Testing GLM's Matrix Multiplication:");

    glm::mat2x2 A(-1.0f, 2.0f, 0.0f, 3.0f);
    glm::vec2 v(2.0f, -1.0f);

    glm::vec2 testResult = v * A;

    LOG_MATRIX(testResult);

    if (argc < 2)
    {
        std::cout << argv[0] << " Version " << MATRIXMULTIPLIER_VERSION_MAJOR << "." << MATRIXMULTIPLIER_VERSION_MINOR << '\n';
        return 1;
    }

    return 0;
}
