PORTNAME=	libreadline-java
PORTVERSION=	0.8.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	7
CATEGORIES=	devel java
MASTER_SITES=	SF/java-readline/java-readline/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JNI wrapper around GNU Readline / libedit / libgetline
WWW=		https://sourceforge.net/projects/java-readline/

USES=		gmake java libedit ncurses readline
JAVA_VERSION=	8

ALL_TARGET=	# empty
MAKE_ENV=	JAVA_HOME="${JAVA_HOME}" JAVA="${JAVA}" JAVAC="${JAVAC}" \
		JAVAH="${JAVAH}" JAR_="${JAR}"
SUB_FILES=	pkg-message jython.sh
PLIST_FILES=	%%JAVAJARDIR%%/libreadline-java.jar \
		lib/libJavaReadline.so \
		lib/libJavaEditline.so \
		lib/libJavaGetline.so
PORTDOCS=	README.1st README jython.sh JReadlineCompleter.py
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libreadline-java.jar \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${WRKSRC}/libJavaReadline.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libJavaEditline.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libJavaGetline.so ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/jython.sh ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/JReadlineCompleter.py \
		${STAGEDIR}${DOCSDIR}

.if !defined(BATCH)
test:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_CMD} test  # Now type something!
.endif

.include <bsd.port.mk>
