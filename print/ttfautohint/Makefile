PORTNAME=	ttfautohint
PORTVERSION=	1.8.4
CATEGORIES=	print
MASTER_SITES=	SAVANNAH/freetype \
		SF/freetype/ttfautohint/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatic font hinting library
WWW=		https://www.freetype.org/ttfautohint/

LICENSE=	FTL GPLv2+
LICENSE_COMB=	dual
LICENSE_NAME_FTL=	The FreeType Project license
LICENSE_FILE_FTL=	${WRKSRC}/FTL.TXT
LICENSE_FILE_GPLv2+ =	${WRKSRC}/GPLv2.TXT
LICENSE_PERMS_FTL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	freetype2>=2.4.5:print/freetype2 \
		harfbuzz>=1.3.0:print/harfbuzz
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang gmake libtool pkgconfig

CONFIGURE_ARGS=	--with-doc=no --with-qt=no
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
