
# Master 节点初始化命令
kubeadm init \
--apiserver-advertise-address=172.31.148.77 \  # 正确：指定 Master 节点的 IP
--image-repository registry.aliyuncs.com/google_containers \  # 国内镜像加速，非常重要
--kubernetes-version v1.25.0 \  # 与安装版本一致，正确
--service-cidr=10.10.0.0/12 \  # 服务网段（与 Pod 网段不重叠，合理）
--pod-network-cidr=10.244.0.0/16 \  # 适配 flannel 网络插件，正确
--cri-socket /var/run/cri-dockerd.sock \  # 关联 cri-dockerd，正确
--ignore-preflight-errors=all  # 建议仅忽略必要错误（如 Swap），但测试环境可暂时用