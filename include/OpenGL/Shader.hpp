class Shader{

    private:
        GLuint id = -1;

        void checkCompileErrors(GLuint shader, std::string type);


    public:

        Shader() = default;
        Shader( const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr );
        // activate the shader
        // ------------------------------------------------------------------------
        void use() 
        { 
            glUseProgram(id); 
        }
        // utility uniform functions
        // ------------------------------------------------------------------------
        void setBool(const std::string &name, bool value) const
        {         
            glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value); 
        }
        // ------------------------------------------------------------------------
        void setInt(const std::string &name, int value) const
        { 
            glUniform1i(glGetUniformLocation(id, name.c_str()), value); 
        }
        // ------------------------------------------------------------------------
        void setFloat(const std::string &name, float value) const
        { 
            glUniform1f(glGetUniformLocation(id, name.c_str()), value); 
        }
        void setVec2(const std::string &name, float x, float y) const
        { 
            glUniform2f(glGetUniformLocation(id, name.c_str()), x, y); 
        }
        void setVec3(const std::string &name, float x, float y, float z) const
        { 
            glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z); 
        }
        void setVec4(const std::string &name, float x, float y, float z, float w) 
        { 
            glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w); 
        }
        

};

#include "Shader.cpp"