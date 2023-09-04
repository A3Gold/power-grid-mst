class vertex {
    public:
        vertex(){
            vertexNum = 0;
            weight = 0;
        }
        vertex(int setVertexNum, int setWeight){
            weight = setWeight;
            vertexNum = setVertexNum;
        }
        int getWeight(){
            return this->weight;
        }
        void setWeight(int weight){
            this->weight = weight;
        }
        int getVertexNum(){
            return this->vertexNum;    
        }
        void setVertexNum(int vertexNum){
            this->vertexNum = vertexNum;
        }

    private:
        int vertexNum;
        int weight;
};