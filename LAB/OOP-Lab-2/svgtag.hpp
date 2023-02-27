using std::cout;
using std::cin;
using std::endl;
using std::string;

class SVG{
    public:
        static bool is_inside(double x, double y){
            double r = 250;
            double a = 250;
            double b = 250;

            if((x - a) * (x - a) + (y - b) * (y - b) <= r * r){
                return true;
            } else {
                return false;
            }
        }

        static string circle_tag(double x, double y){
            string color;

            if(is_inside(x, y)){
                color = "\"green\"";
            } else {
                color = "\"red\"";
            }

            string tag = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y) + "\" r=\"10\" fill=" + color + " />";
            return tag;
        }

        static double map(double x, double in_min, double in_max, double out_min, double out_max){
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }
};