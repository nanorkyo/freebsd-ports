PORTNAME=	grpcox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	27
CATEGORIES=	net www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web based GUI client for gRPC
WWW=		https://github.com/gusaul/grpcox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gusaul
GH_SUBDIR=	src/github.com/gusaul/grpcox
GH_TUPLE=	\
		fullstorydev:grpcurl:v1.3.2:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		golang:net:d8887717615a:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:c66870c02cf8:google_go_genproto/vendor/google.golang.org/genproto \
		gorilla:mux:v1.7.0:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:v1.21.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.5.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
