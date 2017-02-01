#include "widgets.hpp"


namespace rack {

void SpriteWidget::draw(NVGcontext *vg) {
	Vec pos = box.pos.plus(spriteOffset);

	int width, height;
	nvgImageSize(vg, spriteImage->handle, &width, &height);
	int stride = width / spriteSize.x;
	if (stride == 0) {
		printf("Size of SpriteWidget is %d, %d but spriteSize is %f, %f\n", width, height, spriteSize.x, spriteSize.y);
		return;
	}
	Vec offset = Vec((index % stride) * spriteSize.x, (index / stride) * spriteSize.y);
	NVGpaint paint = nvgImagePattern(vg, pos.x - offset.x, pos.y - offset.y, width, height, 0.0, spriteImage->handle, 1.0);
	nvgFillPaint(vg, paint);
	nvgBeginPath(vg);
	nvgRect(vg, pos.x, pos.y, spriteSize.x, spriteSize.y);
	nvgFill(vg);
}


} // namespace rack
