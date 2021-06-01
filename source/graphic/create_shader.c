/*
** EPITECH PROJECT, 2018
** create_shader.c
** File description:
** description
*/

#include "my_rpg.h"

void destroy_shader(shader_t *shader)
{
	sfShader_destroy(shader->shader);
	if (shader->time.clock != NULL) {
		sfClock_destroy(shader->time.clock);
	}
}

shader_t create_shader(char *frag, int is_clock)
{
	shader_t shader;

	shader.shader = sfShader_createFromFile("shader/simple.vert", "shader/simple.vert", frag);
	shader.state.shader = shader.shader;
	shader.state.blendMode = sfBlendAlpha;
	shader.state.transform = sfTransform_Identity;
	shader.state.texture = NULL;
	if (is_clock == 1) {
		shader.time = create_st_time();
	} else {
		shader.time.clock = NULL;
	}
	return (shader);
}
