class edge {
    public:
        edge(){
            a = 0;
            b = 0;
            weight = 0;
        }
        edge(int seta, int setb, int setWeight){
            a = seta;
            b = setb;
            weight = setWeight;
        }
        int getWeight(){
            return this->weight;
        }
        void setWeight(int weight){
            this->weight = weight;
        }
        int geta(){
            return this->a;    
        }
        void seta(int a){
            this->a = a;
        }
        int getb(){
            return this->b;    
        }
        void setb(int b){
            this->b = b;
        }

    private:
        int a;
        int b;
        int weight;
};