# Features of Virtual CPU (vCPU)

A **virtual CPU (vCPU)** is an abstraction of a physical CPU assigned to a virtual machine (VM) in a virtualization environment. Key features include:

- **Abstraction from Hardware**: vCPUs represent a portion of physical CPU resources managed by the hypervisor.
- **Resource Allocation**: The number of vCPUs is configurable based on VM requirements, with the possibility of overcommitting resources.
- **Independent Operation**: Each VM operates with its own isolated vCPU(s), even though resources are shared.
- **Time-Slicing**: The hypervisor schedules vCPUs on physical cores using time-sharing to ensure efficient execution.
- **CPU Affinity**: vCPUs can be pinned to specific physical cores for better performance in certain scenarios.
- **Performance Impact**: vCPUs share physical resources, so performance can be affected by resource contention or overcommitment.
- **Dynamic Scaling**: vCPUs can be added or removed dynamically based on workload needs.
- **Virtual NUMA**: Large VMs with multiple vCPUs may simulate NUMA to optimize memory access.
- **Security Isolation**: vCPUs provide strong isolation between VMs, enhancing security in virtualized environments.

These features allow vCPUs to provide flexibility, scalability, and efficient resource management in virtualized systems.
