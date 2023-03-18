#include <iostream>

// Point structure with x and y as its data fields
struct Point
{
    int x;
    int y;
};

// Dynamic memory allocation function
void *my_alloc(size_t size)
{
    void *p = malloc(size);
    if (p == nullptr)
    {
        std::cerr << "Error: memory allocation failed." << std::endl;
        exit(1);
    }
    return p;
}

// Function to create a list of points out of xlist and ylist
Point *create_point_list(int *xlist, int *ylist, int n)
{
    Point *point_list = static_cast<Point *>(my_alloc(n * sizeof(Point)));
    for (int i = 0; i < n; i++)
    {
        point_list[i].x = xlist[i];
        point_list[i].y = ylist[i];
    }
    return point_list;
}

// Function to split the x and y lists from a list of points
void split_point_fields(Point *point_list, int n, int *&xlist, int *&ylist)
{
    xlist = static_cast<int *>(my_alloc(n * sizeof(int)));
    ylist = static_cast<int *>(my_alloc(n * sizeof(int)));
    for (int i = 0; i < n; i++)
    {
        xlist[i] = point_list[i].x;
        ylist[i] = point_list[i].y;
    }
}

// Function to print a list of points
void print_point_list(Point *point_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "(" << point_list[i].x << ", " << point_list[i].y << ")" << std::endl;
    }
}

// Test program
int main()
{
    // Test create_point_list
    int xlist[3] = {1, 2, 3};
    int ylist[3] = {4, 5, 6};
    Point *point_list = create_point_list(xlist, ylist, 3);
    print_point_list(point_list, 3);
    free(point_list);

    // Test split_point_fields
    point_list = static_cast<Point *>(my_alloc(3 * sizeof(Point)));
    point_list[0] = {1, 4};
    point_list[1] = {2, 5};
    point_list[2] = {3, 6};
    int *xlist2;
    int *ylist2;
    split_point_fields(point_list, 3, xlist2, ylist2);
    for (int i = 0; i < 3; i++)
    {
        std::cout << xlist2[i] << ", " << ylist2[i] << std::endl;
    }
    free(point_list);
    free(xlist2);
    free(ylist2);

    return 0;
}
