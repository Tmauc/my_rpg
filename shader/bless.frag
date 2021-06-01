#version 130

uniform sampler2D texture;

void main()
{
  	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	pixel.r = (pixel.r / 25) * 100;

  	gl_FragColor = pixel;
}
