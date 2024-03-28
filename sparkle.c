#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
// # include "./MLX42/include/MLX42/MLX42.h"
// #include <MLX42/MLX42.h>


#define WIDTH 512
#define HEIGHT 512

// static mlx_image_t* image;


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a); 
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
			    0x90,
				0,
				0xFF,
				0xFF
				// rand() % 0xFF, // R
				// rand() % 0xFF, // G
				// rand() % 0xFF, // B
				// rand() % 0xFF  // A
			);
			// now we draw a couple of separate pixels
			mlx_put_pixel(image, i, y, color);
			mlx_put_pixel(image, 50, 50, 0xFFFFFFFF);
			mlx_put_pixel(image, 49, 49, 0xFFFFFFFF);
			mlx_put_pixel(image, 51, 51, 0xFFFFFFFF);
			mlx_put_pixel(image, 50, 51, 0xFFFFFFFF);
			mlx_put_pixel(image, 51, 50, 0xFFFFFFFF);
			//now we will draw a line(s)
			// Draw parallel lines horizontally
    uint32_t x_start = 10; // Starting x-coordinate of the line
    uint32_t x_end = 90;   // Ending x-coordinate of the line
    uint32_t line_y = 30;  // Y-coordinate of the line

    while (x_start <= x_end)
    {
        mlx_put_pixel(image, x_start, line_y, 0xFFFFFFFF); // Draw a pixel for the line
        x_start++; // Move to the next pixel along the line
    }

    // Draw vertical lines
    uint32_t y_start = 20; // Starting y-coordinate of the line
    uint32_t y_end = 70;   // Ending y-coordinate of the line
    uint32_t line_x = 40;  // X-coordinate of the line

    while (y_start <= y_end)
    {
        mlx_put_pixel(image, line_x, y_start, 0xFFFFFFFF); // Draw a pixel for the line
        y_start++; // Move to the next pixel along the line
    }
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	// width and height of the window
	// name of the window
	// true -> the window should be resizable
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "My_test", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 100, 100) == -1)
	// store the returned index in the variable instance_index
	//after in the code, you can use the stored index instance_index 
	//to reference the image instance whenever needed. 
	//This allows to perform operations on the image, such as moving or modifying it.
	// int32_t instance_index = mlx_image_to_window(mlx, img, 100, 100);
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}