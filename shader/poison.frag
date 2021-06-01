#version 130

uniform sampler2D texture;

void main()
{
  	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	pixel.b = pixel.b / 2;
	pixel.r = pixel.r / 2;

  	gl_FragColor = pixel;
}
