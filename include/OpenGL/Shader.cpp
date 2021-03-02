void Shader::checkCompileErrors(GLuint shader, std::string type){
    GLint success;
    GLchar infolog[1024];
    if (type != "PROGRAM"){
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success){
            glGetShaderInfoLog(shader, 1024, NULL, infolog);
            std::cout << "Shader Compile Error:" << type <<":\n"<<infolog << std::endl;
        }
    }
}


Shader::Shader( const char* vertexPath, const char* fragmentPath, const char* geometryPath ){
    
    // File loading
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    std::ifstream vertexFile(vertexPath);
    std::ifstream fragFile(fragmentPath);
    std::ifstream geoFile(geometryPath);
    std::stringstream reader;
    
    
    try{
        reader << vertexFile.rdbuf();
        vertexCode = reader.str();
        reader = std::stringstream();
        reader << fragFile.rdbuf();
        fragmentCode = reader.str();
        reader = std::stringstream();
        if (geometryPath){
            reader << geoFile.rdbuf();
            geometryCode = reader.str();
        }
    } catch(std::ifstream::failure& e){
        std::cout << "Shader load error" << std::endl;
    }
    vertexFile.close();
    fragFile.close();
    geoFile.close();
    const char* vshader = vertexCode.c_str();
    const char* fshader = fragmentCode.c_str();
    GLuint vertex, fragment, geometry;
    
    // Generate shaders
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vshader, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fshader, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    if (geometryPath){
        const char* gshader = geometryCode.c_str();
        geometry = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometry, 1, &gshader, NULL);
        glCompileShader(geometry);
        checkCompileErrors(geometry,"GEOMETRY");
    }
    // Compile the final program
    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);

    if (geometryPath) glAttachShader(id, geometry);

    glLinkProgram(id);
    checkCompileErrors(id, "PROGRAM");
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    if (geometryPath) glDeleteShader(geometry);

}


