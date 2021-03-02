class Scene{


    private:
        std::vector<Object3D*> objects;
        std::vector<Light*> lights;

    public:
        GLuint target = -1;
        Color background = Color(0,0,0,1);
        Scene(){}
        Scene(Color background) : background(background) {};
        Scene(Texture target) : target(target.id) {};
        Scene(Texture target, Color background) : target(target.id), background(background) {};


        void render(Camera camera);
        void addObject( Object3D* obj ){ objects.push_back(obj); }
        void addLight( Light* light ){ lights.push_back(light); }
};

