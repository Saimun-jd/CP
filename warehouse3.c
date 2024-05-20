#include<stdio.h>

#define MAX_WAREHOUSES 100
#define PI 3.1416

typedef struct {
	float diameter;
} Circle;

typedef struct {
	float width, height;
} Rect;

typedef union {
	Circle circle;
	Rect rect;
} Shape;

typedef struct {
	Shape shape;
	int shape_type;
} Warehouse;

void addCircle(Warehouse* wh, float d, int idx) {
	wh[idx].shape_type = 0;
	wh[idx].shape.circle.diameter = d;
}

void addRect(Warehouse* wh, float w, float h, int idx) {
	wh[idx].shape_type = 1;
	wh[idx].shape.rect.width = w;
	wh[idx].shape.rect.height = h;
}

float calc_area_1(float d) {
	float area = PI*d*d/4;
	return area;
}

float calc_area_2(float w, float h){
	return w*h;
}

float percent(float total, float x){
	float p = (x/total)*100;
	return p;
}

int main(int argc, char* argv[]) {
	Warehouse wh[100];
	int total = 0;
	float c_area = 0.f, r_area = 0.f;
	int c=0, r=0;
	float d, w, h;
	
	int n;
	while (1) { 
        printf("Please select an option from below: \n");
        printf("1. Add Circle\n");
        printf("2. Add Rectangle\n");
        printf("3. List items\n");
        printf("4. Get Statistics\n");
        printf("5. Exit\n");
		scanf("%d", &n);
		float total_area = c_area + r_area;
		switch (n) {
		case 1:
		    printf("Enter diameter of the circle: \n");
			scanf("%f", &d);
			if (total < MAX_WAREHOUSES) {
				c_area += calc_area_1(d);
				c++;
				addCircle(wh, d, total++);
			} else {
				printf("Warehouse is full.\n");
			}
			break;
		case 2:
		    printf("Enter width and height of rect: \n");
		    scanf("%f%f", &w, &h);
		    if(total<MAX_WAREHOUSES){
		    	r_area += calc_area_2(w, h);
		    	r++;
		    	addRect(wh, w, h, total++);
		    } else{
		    	printf("Warehouse is full.\n");
		    }
			break;
		case 3:
			printf("ID---------TYPE-------DIMENSION\n");
			for (int i = 0; i < total; i++) {
				if (wh[i].shape_type == 0) {
					printf("%d        CIRCLE        %.2f\n", i, wh[i].shape.circle.diameter);
				} else{
					printf("%d        RECT        %.2f X %.2f\n", i, wh[i].shape.rect.width, wh[i].shape.rect.height);
				}
			}
			break;
		case 4:
		    printf("Total circle: %d\n", c);
		    printf("Total rectangle: %d\n", r);
		    printf("Total area: %.2f\n", total_area);
		    printf("Total area occupied by circle: %.2f(%.2f%%)\n",c_area, percent(total_area, c_area));
		    printf("Total area occupied by rectangle: %.2f(%.2f%%)\n", r_area, percent(total_area, r_area));
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}