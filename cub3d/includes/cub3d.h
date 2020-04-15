/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:34:29 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/04 18:17:45 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "mlx.h"

# define K_ESC			53
# define K_UP			126
# define K_DOWN		125
# define K_LEFT		123
# define K_RIGHT		124
# define SOUTH	0
# define NORTH	1
# define WEST	2
# define EAST	3
# define SPRITE	4
# define FLOOR		0
# define CEILING	1
# define PARSED_MAP_LINE 99

# define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
# define RGB(r, g, b) RGBA(r, g, b, 0xff)
# define ALPHA(c, a) ((c) | ((a) << 24))

typedef struct	s_mlx_img_list
{
	int							width;
	int							height;
	char						*buffer;
	float						vertexes[8];
	struct s_mlx_img_list		*next;
}				t_mlx_img_list;

typedef struct	s_mlx_img_ctx
{
	unsigned int			texture;
	unsigned int			vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}				t_mlx_img_ctx;

typedef struct	s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}				t_mlx_win_list;

typedef struct	s_mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}				t_mlx_ptr;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_params
{
	t_mlx		mlx;
	char		**map;
	t_list		map2;
	size_t		map_width;
	int			map_height;
	char		found_player;
	int			win_width;
	int			win_height;
	t_img		textures[5];
	t_color		colors[2];
	int			colors_int[2];
	double		x;
	double		y;
	double		angle;
	double		dx;
	double		dy;
	double		dx2;
	double		dy2;
	double		*table_sin;
	double		*table_cos;
	char		key_up;
	char		key_down;
	char		key_left;
	char		key_right;
}				t_params;

typedef struct	s_object
{
	double		a;
	double		b;
	double		dist;
	double		angle;
	double		pos;
}				t_object;

typedef struct	s_ray
{
	int			stepx;
	int			stepy;
	int			x;
	int			y;
	double		distx;
	double		disty;
	double		step_distx;
	double		step_disty;
	int			vert;
	double		dist;
	double		pos;
	t_list		*lst_objects;
}				t_ray;

typedef struct	s_drawer
{
	int			start;
	int			end;
	int			width_texture;
	int			height_texture;
	double		step_posy;
	int			index_texture;
}				t_drawer;

# define LIBATTOPNG_ADLER_BASE 65521

static const uint32_t g_libattopng_crc32[256] =
{
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
	0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
	0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
	0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
	0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
	0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
	0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
	0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
	0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
	0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
	0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
	0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
	0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
	0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
	0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
	0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
	0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
	0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
	0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
	0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
	0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
	0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

typedef enum	e_libattopng_type{
	PNG_GRAYSCALE = 0,
	PNG_RGB = 2,
	PNG_PALETTE = 3,
	PNG_GRAYSCALE_ALPHA = 4,
	PNG_RGBA = 6
}				t_libattopng_type;

typedef struct	s_libattopng{
	t_libattopng_type	type;
	size_t				capacity;
	char				*data;
	uint32_t			*palette;
	size_t				palette_length;
	size_t				width;
	size_t				height;
	char				*out;
	size_t				out_pos;
	size_t				out_capacity;
	uint32_t			crc;
	uint16_t			s1;
	uint16_t			s2;
	size_t				bpp;
	size_t				stream_x;
	size_t				stream_y;
}				t_libattopng;

typedef struct	s_libstuff{
	size_t			bpl;
	size_t			raw_size;
	size_t			size;
	size_t			p;
	size_t			pos;
	size_t			corr;
	unsigned char	*pixel;

}				t_libstuff;

int				libattopng_new_sub1(t_libattopng_type type,
					t_libattopng *png);
int				libattopng_new_sub2(t_libattopng_type type,
					t_libattopng *png);
int				libattopng_get_data_sub1(t_libattopng *png, size_t *len);
void			libattopng_get_data_sub2(t_libattopng *png, size_t *ps,
								char *entry, size_t *pindex);
void			libattopng_get_data_sub3(t_libattopng *png, t_libstuff *pa,
					size_t *pindex);
void			libattopng_get_data_sub4(t_libattopng *png, t_libstuff *pa,
					size_t *pindex);

t_libattopng	*libattopng_new(size_t width, size_t height,
					t_libattopng_type type);
int				libattopng_set_palette(t_libattopng *png, uint32_t *palette,
					size_t length);
void			libattopng_set_pixel(t_libattopng *png, size_t x, size_t y,
					uint32_t color);
uint32_t		libattopng_get_pixel(t_libattopng *png, size_t x, size_t y);
void			libattopng_start_stream(t_libattopng *png, size_t x, size_t y);
void			libattopng_put_pixel(t_libattopng *png, uint32_t color);
uint32_t		libattopng_swap32(uint32_t num);
uint32_t		libattopng_crc(const unsigned char *data, size_t len,
								uint32_t crc);
void			libattopng_out_raw_write(t_libattopng *png,
											const char *data, size_t len);
void			libattopng_out_raw_uint(t_libattopng *png, uint32_t val);
void			libattopng_out_raw_uint16(t_libattopng *png, uint16_t val);
void			libattopng_out_raw_uint8(t_libattopng *png, uint8_t val);
void			libattopng_new_chunk(t_libattopng *png, const char *name,
										size_t len);
void			libattopng_end_chunk(t_libattopng *png);
void			libattopng_out_uint32(t_libattopng *png, uint32_t val);
void			libattopng_out_uint16(t_libattopng *png, uint16_t val);
void			libattopng_out_uint8(t_libattopng *png, uint8_t val);
void			libattopng_out_write(t_libattopng *png, const char *data,
					size_t len);
void			libattopng_out_write_adler(t_libattopng *png,
					unsigned char data);
void			libattopng_pixel_header(t_libattopng *png, size_t offset,
					size_t bpl);
char			*libattopng_get_data(t_libattopng *png, size_t *len);
int				libattopng_save(t_libattopng *png, const char *filename);
void			libattopng_destroy(t_libattopng *png);

int				init_mlx_win(t_params *p);
double			dist(double x1, double y1, double x2, double y2);
int				hook_keydown(int key, t_params *p);
int				hook_keyup(int key, t_params *p);
int				close_win(t_params *p);
void			draw(t_params *p);
int				loop_listener(t_params *p);

void			init_params(t_params *p);
int				init_mlx(t_params *p);
int				print_error(t_params *p, char *message);
void			update_orientation(t_params *p);
void			free_static_tab(void **tab, int size);
void			turn_right(t_params *p);
void			turn_left(t_params *p);
void			go_backward(t_params *p);
void			go_forward(t_params *p);

double			decimal_part(double a);
void			init_ray(t_params *p, t_ray *pray);
void			compute_ray(t_params *p, t_ray *pray);

int				count_words(char **words);
void			free_words(char **words);
int				parse_sub_texture(t_params *p, char **words, int index);
int				parse_sub_resolution(t_params *p, char **words);
int				parse_sub_color(t_params *p, char **words,
								int floor_or_ceiling);
int				check_line(t_params *p, char *line);
int				parse_map(t_params *p, char *line);
int				check_and_store_map(t_params *p);
int				parse_sub(t_params *p, char **words, char *line);
int				parse(t_params *p, int fd);
void			draw_column(t_params *p, int column, t_ray *pray,
							t_drawer *pdrawer);
void			try_free(void **ppointer);
void			try_free_all(t_params *p);

#endif
