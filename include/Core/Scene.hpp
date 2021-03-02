class Scene{


    private:
        //vector<Object3D*> objects;

    public:
        GLuint target = -1;
        Color background = Color(0,0,0,1);
        Scene(){}
        Scene(Color background) : background(background) {};
        Scene(Texture target) : target(target.id) {};
        Scene(Texture target, Color background) : target(target.id), background(background) {};


        void render(Camera camera);


};

