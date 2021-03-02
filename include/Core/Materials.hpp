class ShaderMaterial : public Material{
    public:
    Shader shader;
    void activate() override { shader.use(); }

};