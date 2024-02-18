#include "Widget.h"

Widget::Widget()
	:_shader(nullptr), _texture(nullptr)
{
}

void Widget::Init()
{
	_shader = std::make_shared<Shader>();
	_shader->AttachShader("../assets/shaders/widgets_vertex.shader");
	_shader->AttachShader("../assets/shaders/widgets_fragment.shader");

	_texture = std::make_shared<Texture>("../assets/textures/text.png");
	LOG_INFO(std::to_string(_texture->GetWidth()));
	LOG_INFO(std::to_string(_texture->GetHeight()));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	_vao = std::make_shared<VertexArray>(layout);
}

stm::matrix<float, 4, 2> GetLetterTextureCoords(char letter)
{
	uint8_t offset = letter - 'a';
	uint32_t pixelXLeft = 1 + (offset * 9);
	uint32_t pixelXRight = pixelXLeft + 7;
	uint32_t pixelYUp = 1;
	uint32_t pixelYDown = 9;
	uint32_t width = 235, height = 10;

	stm::matrix<float, 4, 2> out = {
		(float)(pixelXLeft)  / (float)(width), (float)(pixelYDown) / (float)(height),
		(float)(pixelXLeft)  / (float)(width), (float)(pixelYUp)   / (float)(height),
		(float)(pixelXRight) / (float)(width), (float)(pixelYUp)   / (float)(height),
		(float)(pixelXRight) / (float)(width), (float)(pixelYDown) / (float)(height)
	};

	return out;
}

void Widget::Begin()
{

}

void Widget::End()
{

}

void Widget::OnRender(Renderer& renderer, Window& window)
{
	std::string message = "voxelgametest";
	stm::vec2f pos = { -1.f, -0.5f };
	stm::vec2f size{ .05f, .05f };

	std::vector<stm::mat4f> vertex;
	vertex.reserve(message.length());
	std::vector<stm::vector<uint32_t, 6>> index;
	index.reserve(message.length());

	uint32_t offset = 0;

	for (char letter : message)
	{
		auto texCoords = GetLetterTextureCoords(letter);
		vertex.push_back({
			pos.x + (size.x * offset), pos.y, texCoords[0][0], texCoords[0][1],
			pos.x + (size.x * offset), pos.y + size.y , texCoords[1][0], texCoords[1][1],
			pos.x + size.x + (size.x * offset), pos.y + size.y, texCoords[2][0], texCoords[2][1],
			pos.x + size.x + (size.x * offset), pos.y , texCoords[3][0], texCoords[3][1]
			});

		index.push_back({ 0, 1, 2, 0, 2, 3 });
		index.back() += (offset * 4);
		++offset;
	}

	std::shared_ptr<VertexBuffer> vbo = std::make_shared<VertexBuffer>(vertex[0].GetData(), vertex.size() * sizeof(stm::mat4f));
	std::shared_ptr<IndexBuffer> ibo = std::make_shared<IndexBuffer>(index[0].GetData(), index.size() * 6);
	_vao->Bind();
	renderer.BindShader(_shader);
	renderer.DrawQuad(vbo, ibo, _texture, stm::scale(1.0f, (float)window.GetWidth() / (float)window.GetHeight(), 1.0f));
}

Widget::~Widget()
{
}